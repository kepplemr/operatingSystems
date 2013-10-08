/*
 * File:   aclock.h
 * Author: Michael Kepple
 * Date:   28 Mar 2013
 *
*/
#ifndef ACLOCK_H
#define ACLOCK_H
#include <unistd.h>
#include <curses.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define HOUR_LENGTH .5
#define MIN_LENGTH .75
#define CURSOR_OFF 0
#define SECOND 0
#define MINUTE 1
#define HOUR 2
#define HOURS 12
#define FREQ 6
#define HOURVAL 5
#define MINUTEVAL 10
#define DEGREES 360
#define QUARTEROFFSET 15
#define HALFOFFSET 2
#define PI 3.14159265358979323846
#define MIN(a,b) (((a)<(b))?(a):(b))
#define DEG2RAD(Deg) ((Deg) / 180.0 * PI)
void drawClock(int cenX, int cenY, int maxRadius);
void drawHand(int hand, int value, int cenX, int cenY, int maxRadius);
#endif

