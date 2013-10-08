/*
 * File:   threadex.h
 * Author: Michael Kepple
 * Date:   02 Apr 2013
 *
*/
#ifndef THREADEX_H
#define THREADEX_H
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
typedef enum
{
    FALSE,
    TRUE
} boolean;
void produce();
void consume();
boolean oddOnes(int number);
#define MAX_SEQUENCE 1000
#define PRODUCER_WAIT 3
#define CONSUMER_WAIT 1
#endif
