/*
 * File:   msleepdelay.c
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 * Note:   usleep() deprecated POSIX.1-2001
*/
#include "ring.h"
#define MIL2NANO 1000000
#define MIL2SECS 1000

void msleepDelay(int milliseconds)
{
    struct timespec time;
    sigset_t set;
    int seconds = milliseconds / MIL2SECS;
    milliseconds %= MIL2SECS;
    sigfillset(&set);
    // Block all signals while sleeping
    sigprocmask(SIG_BLOCK, &set, NULL);
    time.tv_sec = seconds;
    time.tv_nsec = milliseconds * MIL2NANO;
    if (nanosleep(&time, NULL) < 0)
    {
	perror("nanosleep");
	exit(EXIT_FAILURE);
    }
    printf("RING!!!");
}
