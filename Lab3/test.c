/*
 *
 * test.c
 *
 * Author:      Michael Kepple
 * Date:        24 Apr 2013
 * Description: test file for magic8 driver functionality.
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include "magic8.h"

int main()
{
    int fd;
    printf("Testing Sequential/Original Case:\n");
    fd = open("/dev/magic8", 0);
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    printf("Testing Random/Uppercase:\n");
    ioctl(fd, SET_RANDOM, NULL);
    ioctl(fd, SET_UPPER, NULL);
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    printf("Testing Random/Lowercase/Stoked:\n");
    ioctl(fd, SET_LOWER, NULL);
    ioctl(fd, SET_STOKED, NULL);
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    system("cat /dev/magic8");
    ioctl(fd, SET_ORIG, NULL);
    ioctl(fd, SET_SEQUENTIAL, NULL);
    ioctl(fd, SET_NOT_STOKED, NULL);
}
