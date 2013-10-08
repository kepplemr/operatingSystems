/*
 * File:   magic8.h
 * Author: Michael Kepple
 * Date:   24 Apr 2013
*/
#ifndef __MAGIC8_H
#define __MAGIC8_H
#define NUM_RESPONSES 5
#define SET_SEQUENTIAL 0
#define SET_RANDOM 1
#define SET_ORIG 2
#define SET_UPPER 3
#define SET_LOWER 4
#define SET_STOKED 5
#define SET_NOT_STOKED 6
#define SEQUENTIAL 0
#define RANDOM 1
#define ORIGINAL 0
#define UPPER 1
#define LOWER 2
#define NOT_STOKED 0
#define STOKED 1
int CASE;
int SEQ;
int STOKE;
char *answers[5] = {"0 No", "1 Yes", "2 Maybe", "3 Not a chance in hell",
    "4 Ab-so-lutely"};
#endif
