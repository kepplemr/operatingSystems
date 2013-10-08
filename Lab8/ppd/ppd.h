/* 
 * File:   ppd.h
 * Author: Michael Kepple
 * Date:   2 Apr 2013
 *
*/
#ifndef PPD_H
#define PPD_H
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/sem.h>
#include <time.h>
void printMessage(void * arguments);
typedef struct
{
    char msg[50];
    int delay;
} Args;
const char* const HEY_MSG = "Hello!";
const char* const BYE_MSG = "Goodbye!";
#define HELLO_WAIT 300000000L
#define BYE_WAIT 700000000L
#define N_IN_SEC 1000000000L
#define U_IN_NANO 1000
#endif
