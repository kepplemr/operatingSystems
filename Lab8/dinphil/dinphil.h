/* 
 * File:   dinphil.h
 * Author: Michael Kepple
 * Date:   02 Apr 2013
 *
*/
#ifndef DINPHIL_H
#define DINPHIL_H
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define N 5
#define LEFT (philosopher+N-1)%N
#define RIGHT (philosopher+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
void * philosopher(void *);
void take_forks(int);
void put_forks(int);
void test_forks(int);
#endif
