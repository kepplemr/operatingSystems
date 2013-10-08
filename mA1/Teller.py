#!/usr/bin/env python
"""
Author: Michael Kepple
Date:   23 Mar 2013
Desc:   SimPy simulation of a single-teller Bank teller
"""
from SimPy.Simulation import *
from random import expovariate, seed

# Constant values for initial simulation environment
BEGINTIME = 0
SECINHOUR = 3600
MAXCUSTOMERS = 1000
INTERARRIVAL = 60
SERVICE = 45

class Source(Process):
    """Generates customers for simulation"""
    def generate(self,number,interarrival,resource):
        for i in range(number):
            tempCust = Customer(name = "Customer%02d"%(i,))
            activate(tempCust, tempCust.visit())
            yield hold, self, interarrival

class Customer (Process):
    """Customer arrives, looks around, and leaves"""
    def visit(self):
        arrive=now()
        yield request,self,teller
        yield hold, self, SERVICE
        yield release, self, teller
        serviceWait = now()-arrive
        simMon.observe(serviceWait)
        simMon.min = min(simMon.min, serviceWait)
        simMon.max = max(simMon.max, serviceWait)

## Model/Experiment
teller = Resource(name="Teller", unitName="Teller")
simMon = Monitor()
simMon.min = sys.maxint
simMon.max = -sys.maxint
initialize()
world = Source(name='OutsideWorld')
activate(world,world.generate(number=MAXCUSTOMERS, interarrival=INTERARRIVAL, resource=teller),at=BEGINTIME)
simulate(until=SECINHOUR)
print "Customers Served: %d"%simMon.count()
print "Average Service Time (secs): %d"%simMon.mean()
print "Maximum Service Time (secs): %d"%simMon.max
print "Minimum Service Time (secs): %d"%simMon.min