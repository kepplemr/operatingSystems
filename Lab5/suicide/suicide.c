/*
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 *
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int pid = getpid();
    kill(pid, 9);
    fprintf(stderr, "Failed suicide attempt\n");
    exit(EXIT_FAILURE);
}
