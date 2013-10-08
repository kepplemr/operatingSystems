/*
 * x25.c
 *
 * Author: Michael Kepple
 * Date:   25 Mar 2013
 * Description: prints out a large 'X' centered in a 25x25 square.
*/
#include "x25.h"

int main()
{
    int x,y;
    initscr();
    curs_set(NO_CURSOR);
    for (x=0,y=0; x<SQUARESIDE+1; x++,y++)
    {
        mvwaddch(stdscr, x, y, '\\');
        mvwaddch(stdscr, y, SQUARESIDE-x, '/');
        mvwaddch(stdscr, y, STATIC, '|');
        mvwaddch(stdscr, STATIC, x, '_');
        mvwaddch(stdscr, SQUARESIDE, x, '_');
        mvwaddch(stdscr, y, SQUARESIDE, '|');
    }
    refresh();                 
    getch();
    endwin();
    return 0;
}
