/*
 * ctrinput.c
 *
 * Author: Michael Kepple
 * Date:   28 Mar 2013
 * Decription: accepts user input string, centers it vertically and
 *             horizontally on the screen.
*/
#include "ctrinput.h"

int main()
{
    initscr();
    wmove(stdscr, LINES-2, 0);
    hline('_', COLS);
    mvwprintw(stdscr, LINES-1, 0, "> ");
    wmove(stdscr, LINES-1, 2);
    char str[100];
    getstr(str);
    curs_set(0);
    int strLength = strlen(str)/2;
    mvwprintw(stdscr, LINES/2, (COLS/2-strLength), str);
    refresh();
    getch();
    endwin();
}
