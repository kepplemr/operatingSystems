/*
 * File:   timer.c
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 * Note:   Input is assumed to be valid.
 *
*/
#include "timer.h"
bool ringBack;

int main(int argc, char* argv[])
{
    ringBack = false;
    struct sigaction action;
    int delay = atoi(argv[1]);
    alarm(delay);
    action.sa_handler = timer;
    sigemptyset(&action.sa_mask);
    if (sigaction(SIGALRM, &action, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    while (!ringBack) {}
    printf("RING!\n");
}

void timer(int seconds)
{
    ringBack = true;
}
