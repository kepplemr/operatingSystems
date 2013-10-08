// pwfhisto.c
//
// Author: Michael Kepple
// Date: 9 Feb 2013
// Description: Counts and graphically displays the number of alphanumeric chars
//   found in the /etc/passwd file.
//
#include "pwfhisto.h"

int main ()
{
    FILE *fp;
    int count[ALPHANUM] = {0};
    int charIndex, i, max = 0;
    // Read passwd file and populate char-count array
    if (fp = fopen("/etc/passwd", "r"))
    {
        while ((charIndex = fgetc(fp)) != EOF)
        {
            if (charIndex >= 48 && charIndex <= 57)
                count[(charIndex-48)]++;
            else if (charIndex >= 65 && charIndex <= 90)
                count[(charIndex-55)]++;
            else if (charIndex >= 97 && charIndex <=122)
                count[(charIndex-61)]++;
        }
    }
    else
        exit(EXIT_FAILURE);
    // Find maximum occuring characters
    for (i = 0; i < ALPHANUM; i++)
        if (count[i] > max)
            max = count[i];
    printGraph(count, max);
    getAverages();
}

// Function: printGraph
// Description: given a passed in char-count array and a max, function will
//   display a scaled vertical histogram graph.
// Params: integer char-count array, maximum element within array
// Returns: Nothing.
// Modifies: Nothing.
void printGraph(int *count, int max)
{
    int i, j, cutoff;
    double sensitivity = (double)max/24;
    for (i = 0; i < 24; i++)
    {
        cutoff = (int)(max-(i * sensitivity));
        printf("%5d  ", cutoff);
        for (j = 0; j < 62; j++)
        {
            if (count[j] >= cutoff)
                printf("X");
            else
                printf(" ");
            if (j==9 || j==35)
                printf(" ");
        }
        printf("\n");
    }
    printf("       ----------------------------------------------------------------\n");
    printf("       0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz\n");
}

// Function: getAverages
// Description: traverses through each line of /etc/passwd, summing the UID/GIDs
//   and then calculating their averages.
// Params: None.
// Returns: Nothing.
// Modifies: Nothing.
void getAverages()
{
    int lineCount, uidSum, gidSum = 0;
    char *uid, *gid;
    char line[200];
    FILE *fp = fopen("/etc/passwd", "r");
    while (fgets(line, sizeof line, fp) != NULL)
    {
        strtok(line,":");
        strtok(NULL, ":");
        uid = strtok(NULL, ":");
        gid = strtok(NULL, ":");
        uidSum += atoi(uid);
        gidSum += atoi(gid);
        lineCount++;
    }
    printf("Average UID: %d\n", (uidSum/lineCount));
    printf("Average GID: %d\n", (gidSum/lineCount));
    fclose(fp);
}

