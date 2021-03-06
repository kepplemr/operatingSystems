// ppdir.c
//
// Author: Michael Kepple
// Date: 9 Feb 2013
// Description: given a command line parameter specifying a directory, ppdir
//   displays each inone number and entry name corresponding to files in the dir.
// 
#include "ppdir.h"

int main(int argc, char*argv[])
{
    int fd[2];
    DIR *dir;
    struct dirent *dirInfo;
    bool sort;
    if (getopt(argc, argv, "s:") != -1)
    {
        sort = true;
        argv[1] = argv[2];
    }
    if (argc < 2 || (dir=opendir(argv[1]))==NULL)
    {
        printf("Error: directory not found.\n");
        exit(1);
    }
    printf("===============================================================\n");
    printf("       File/Dir Name   ->   Inode Number\n");
    printf("===============================================================\n");
    if (!sort)
    {
        while (dirInfo = readdir(dir))
            printf("%20s   ->   %lld\n", dirInfo->d_name, (long long)dirInfo->d_ino);
    }
    else
    {
        pipe(fd);
        if (fork() == 0)
        {
            if (close(fd[0]) == -1)
            {
                perror("close");
                exit(EXIT_FAILURE);
            }
            if (dup2(fd[1], 1) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            if (close(fd[1]) == -1)
            {
                perror("close");
                exit(EXIT_FAILURE);
            }
            while (dirInfo = readdir(dir))
                printf("%20s   ->   %lld\n", dirInfo->d_name, (long long)dirInfo->d_ino);
            if (closedir(dir) == -1)
            {
                perror("closedir");
                exit(EXIT_FAILURE);
            }
            exit(0);
        }
        else
        {
            if (close(fd[1]) == -1)
            {
                perror("close");
                exit(EXIT_FAILURE);
            }
            if (dup2(fd[0], 0) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            if (close(fd[0]) == -1)
            {
                perror("close");
                exit(EXIT_FAILURE);
            }
            execl("/bin/sort", "sort", "-k 1,1", NULL);
            perror("execl");
            exit(EXIT_FAILURE);
        }
    }
    if (closedir(dir) == -1)
    {
        perror("closedir");
        exit(EXIT_FAILURE);
    }
}
