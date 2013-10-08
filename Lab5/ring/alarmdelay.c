/*
 * File:   alarmdelay.c
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 *
*/
#include "ring.h"

void alarmDelay(int seconds)
{
    sigset_t blockSet;
    struct sigaction action;
    action.sa_handler = timer;
    sigemptyset(&action.sa_mask);
    if (sigaction(SIGALRM, &action, NULL) < 0)
    {
	    perror("sigaction");
	    exit(EXIT_FAILURE);
    }
    sigfillset(&blockSet);
    sigdelset(&blockSet, SIGALRM);
    alarm(seconds);
    sigsuspend(&blockSet);
    printf("RING!!!");
}

// Empty non-lethal SIGALRM handler
void timer() {}
