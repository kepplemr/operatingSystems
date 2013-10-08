/*
 * cclock.c
 *
 * Author: Michael Kepple
 * Date:   28 Mar 2013
 * Description: Digital clock implentation through curses.
*/
#include "cclock.h"

int main()
{
    initscr();
    curs_set(CURSOR_OFF);
    time_t curTime;
    struct tm *localTime;
    int hourPos, minPos, secPos, cenY, cenX;
    for (;;)
    {
        time(&curTime);
        localTime = localtime(&curTime);
        hourPos = localTime->tm_hour;
        minPos = localTime->tm_min;
        secPos = localTime->tm_sec;
        cenX = MAX(0,((COLS-CLOCK_WIDTH)/2));
        cenY = LINES/2-HALF_HEIGHT;
        printTime(hourPos, cenX, cenY);
        cenX+=TIME_WIDTH;
        printColon(cenX, cenY);
        cenX+=COL_WIDTH;
        printTime(minPos, cenX, cenY);
        cenX+=TIME_WIDTH;
        printColon(cenX, cenY);
        cenX+=COL_WIDTH;
        printTime(secPos, cenX, cenY);
        refresh();
        sleep(1);
    }
    refresh();
    getch();
    endwin();
}

/*
 * Function: printTime
 * Description: prints out two digits at specified location representing time.
 * Params: time, beginning x-coordinates and y-coordinates.
 * Returns: Nothing.
 * Modifies: stdscr
*/
void printTime(int time, int x, int y)
{
    int firstDig = (int)(time/BASE);
    int secDig = time % BASE;
    int i;
    for (i = 0; i<HEIGHT;i++)
        mvwprintw(stdscr, (y+i), x, "%s",clockChars[firstDig][i]);
    for (i = 0; i<HEIGHT;i++)
        mvwprintw(stdscr, (y+i), (x+COL_WIDTH), "%s",clockChars[secDig][i]);
}

/* 
 * Function: printColon
 * Description: displays a large colon character to the screen at specified
 *   location.
 * Params: x-coordinate and y-coordinate to begin displaying colon.
 * Returns: Nothing.
 * Modifies: stdscr
*/
void printColon(int x, int y)
{
    int i;
    for (i = 0; i<HEIGHT;i++)
        mvwprintw(stdscr, (y+i), x, "%s", clockChars[COL_INDEX][i]);
}
