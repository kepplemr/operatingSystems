/*
 * edgeworm.c
 *
 * Author: Michael Kepple
 * Date:   25 Mar 2013
 * Description: 'worm-like' text slides around the borders of the screen.
*/
#include "edgeworm.h"

int main()
{
    char text[] = "MICHAEL";
    initscr();
    COLS--;
    LINES--;
    int rWall = COLS;
    int dWall = rWall + LINES;
    int lWall = dWall + rWall;
    curs_set(NO_CURSOR);
    int i=0,j=0,currPos=0;
    int totalChars = (COLS)*2+(LINES)*2;
    for (;;i++)
    {
        clear();
        i %= totalChars;
        for (j=0; j<NAMELENGTH; j++)
        {
            currPos = i+j;
            if (currPos < rWall)
                mvwaddch(stdscr, 0, currPos, text[j]);
            else if (currPos < dWall)
                mvwaddch(stdscr, (currPos-rWall), COLS, text[j]);
            else if (currPos < lWall)
                mvwaddch(stdscr, LINES, (lWall-currPos), text[j]);
            else
                mvwaddch(stdscr, ((LINES+lWall)-currPos), 0, text[j]);
        }
        struct timespec waitTime;
        waitTime.tv_nsec = NANOSLEEP;
        refresh();
        nanosleep(&waitTime, NULL);
    }
    getch();
    endwin();
    return 0;
}
