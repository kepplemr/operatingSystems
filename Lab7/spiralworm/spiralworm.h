/*
 * File:   spiralworm.h
 * Author: Michael Kepple
 * Date:   28 Mar 2013
 *
*/
#ifndef SPIRALWORM_H
#define SPIRALWORM_H
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#define MAXLENGTH 7
#define NANOSLEEP 10000000L
typedef struct Node Node;
typedef struct Queue Queue;
struct Node
{
    int x;
    int y;
    char ch;
    Node * next;
};
struct Queue
{
    Node * head;
    Node * tail;
    int size;
};
void enqueue(Queue * queue, int x, int y, char ch);
Node * dequeue(Queue * queue);
#endif
