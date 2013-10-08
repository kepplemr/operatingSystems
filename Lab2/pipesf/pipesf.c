// pipesf.c
//
// Author: Michael Kepple
// Date: 9 Feb 2013
// Description: Connects three processes with pipes, this time using pipe(2).
//
#include "pipesf.h"

int main(int argc, char *argv[])
{
    char buffer[200];
    memset(&buffer[0], 0, sizeof(buffer));
    int i=0, j=0, status, count=0;
    if (F == 0)
    {
        int pipefds[6];
        for (i =0; i < 3; i++)
            pipe(pipefds + i * 2);
        for (i = 0; i <= 6;)
        {
            if (fork() == 0)
            {
                memset(&buffer[0], 0, sizeof(buffer));
                if (i != 6)
                    dup2(pipefds[i+1], 1);
                if (i != 0)
                    dup2(pipefds[i-2], 0);
                if (i == 0)
                    printf("%s", argv[1]);
                fflush(stdout);
                for (j = 0; j <= 6; j++)
                    close(pipefds[j]);
                snprintf(buffer, sizeof(buffer), "p%d", count);
                execl(buffer, "we", NULL);
            }
            count++;
            i+=2;
        }
        for (j = 0; j <= 6; j++)
            close(pipefds[j]);
        for (j = 0; j < 2; j++)
            wait(&status);
        waitpid();
        printf("\n");
    }
    else
    {
        read(0, buffer, sizeof(buffer));
        printf("%s%d", buffer, F);
    }
}
