// pipes.c
//
// Author: Michael Kepple
// Date: 9 Feb 2013
// Description: Connects three processes with pipes.
//
#include "pipes.h"

int main(int argc, char *argv[])
{
    int fd[2];
    char buffer[100];
    // pipe3
    if (F == 0)
    {
        sprintf(buffer, "p1 %s | p2 | p3", argv[1]);
        system(buffer);
    }
    // p1
    else if (F == 1)
        printf("%s1", argv[1]);
    // p2
    else if (F == 2)
    {
        read(fd[0], buffer, sizeof(buffer));
        printf("%s2", buffer);
    }
    // p3
    else
    {
        read(fd[0], buffer, sizeof(buffer));
        printf("%s3\n", buffer);
    }
}
