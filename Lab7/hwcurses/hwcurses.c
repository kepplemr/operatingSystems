/*
 * hwcurses.c
 *
 * Author: Michael Kepple
 * Date:   25 Mar 2013
 * Description: Uses ncurses to print out a screen-centered "Hello, World!"
*/
#include "hwcurses.h"

int main()
{
    initscr();
    curs_set(NO_CURSOR);
    mvprintw(LINES/2, (COLS/2-STRLENGTH/2), "Hello, World!");
    refresh();                 
    getch();
    endwin();
    return 0;
}
