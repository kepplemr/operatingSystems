// ppfstats.c
//
// Author: Michael Kepple
// Date: 9 Feb 2013
// Description: A far more visually pleasant presentation of standard stat 2
//   output.
//
#include "ppfstats.h"

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Filename argument expected.\n");
        exit(-1);
    }
    struct stat buffer;
    if (stat(argv[1], &buffer) == -1)
        exit(-1);
    printf("================================================================\n");
    printf("File Stats for: %s\n", argv[1]);
    printf("================================================================\n");
    printf("Device ID: %llx\n", (long long) buffer.st_dev);
    printf("Major DID: %llx\n", (long long) major(buffer.st_dev));
    printf("Minor DID: %llx\n", (long long) minor(buffer.st_dev));
    printf("Inode: %lld\n", (long long) buffer.st_ino);
    printf("File Permissions (Octal): %04o\n", buffer.st_mode%32768);
    printf("File Permissions: ");
    printf((S_ISDIR(buffer.st_mode)) ? "d" : "-");
    printf((buffer.st_mode & S_IRUSR) ? "r" : "-");
    printf((buffer.st_mode & S_IWUSR) ? "w" : "-");
    printf((buffer.st_mode & S_IXUSR) ? "x" : "-");
    printf((buffer.st_mode & S_IRGRP) ? "r" : "-");
    printf((buffer.st_mode & S_IWGRP) ? "w" : "-");
    printf((buffer.st_mode & S_IXGRP) ? "x" : "-");
    printf((buffer.st_mode & S_IROTH) ? "r" : "-");
    printf((buffer.st_mode & S_IWOTH) ? "w" : "-");
    printf((buffer.st_mode & S_IXOTH) ? "x\n" : "-\n");
    printf("Number of hard links: %lld\n", (long long)buffer.st_nlink);
    printf("UID of File: %d\n", buffer.st_uid);
    printf("GID of File: %d\n", buffer.st_gid);
    printf("Size in Bytes: %lld\n", (long long) buffer.st_size);
    time_t time = buffer.st_atime;
    printf("Last Accessed: %s", ctime(&time));
    time = buffer.st_mtime;
    printf("Last Modified: %s", ctime(&time));
    time = buffer.st_ctime;
    printf("Last Changed: %s", ctime(&time)); 
}
