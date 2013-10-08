/*
 * File:   purgatory.c
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 *
*/
#include "purgatory.h"
#define FINAL_MINUTES 5
bool beenShot;
bool pushingDaisies;

int main()
{
    beenShot = false;
    pushingDaisies = false;
    struct sigaction term;
    struct sigaction alrm;
    term.sa_handler = mortallyInjure;
    alrm.sa_handler = death;
    sigemptyset(&term.sa_mask);
    sigemptyset(&alrm.sa_mask);
    if (sigaction(SIGTERM, &term, NULL) < 0)
    {
	perror("sigaction - term");
	exit(EXIT_FAILURE);
    }
    if (sigaction(SIGALRM, &alrm, NULL) < 0)
    {
	perror("sigaction - alrm");
	exit(EXIT_FAILURE);
    }
    while (!beenShot) {} 
    printf("Goodbye...\n");
    alarm(FINAL_MINUTES);
    while (!pushingDaisies) {}
    printf("\n...cruel signal!\n");
}

// SIGTERM Handler
void mortallyInjure()
{
    beenShot = true;
}

// SIGALRM Handler
void death()
{
    pushingDaisies = true;
}
