/*
 * File:   sendsig.c
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 *
*/
#include "sig.h"
#define MAXPIDLEN 10

int main()
{
    FILE *file;
    file = fopen("temp.pid", "rt");
    char str[MAXPIDLEN];
    int pid = atoi(fgets(str, MAXPIDLEN, file));
    kill(pid, SIGUSR1);
    remove("temp.pid");
}
