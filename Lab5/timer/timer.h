/*
 * File:   timer.h
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 *
*/
#ifndef TIMER_H
#define TIMER_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
typedef int bool;
#define true 1
#define false 0
void timer(int seconds);
#endif
