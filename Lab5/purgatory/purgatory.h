/*
 * File:   purgatory.h
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 *
*/
#ifndef PURGATORY_H
#define PURGATORY_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
typedef int bool;
#define true 1
#define false 0
void mortallyInjure();
void death();
#endif
