/*
 * File:   ring.h
 * Author: Michael Kepple
 * Date:   21 Feb 2013
*/
#ifndef RING_H
#define RING_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
typedef int bool;
#define true 1
#define false 0
#define MAX_INT 2147483647
int ad2b(char* value);
void alarmDelay(int seconds);
void timer();
#endif
