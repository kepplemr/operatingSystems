/*
 * File:   annsig.c
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 *
*/
#include "sig.h"
bool ringBack;

int main()
{
    ringBack = false;
    int pid = getpid();
    struct sigaction action;
    action.sa_handler = usr;
    sigemptyset(&action.sa_mask);
    if (sigaction(SIGUSR1, &action, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    FILE *file;
    file = fopen("temp.pid", "w+");
    fprintf(file, "%d\n", pid);
    fclose(file);
    while (!ringBack) {}
    printf("\nSIGUSR1 signal received!\n");
}

// SIGUSR Handler
void usr()
{
    ringBack = true;
}
