/*
 * rinr.c
 *
 * Author: Michael Kepple
 * Date:   25 Mar 2013
 * Description: draws successively smaller rectangles on the screen until there
 *   is room for no additional rectangles.
*/
#include "rinr.h"

int main()
{
    int x,y,i;
    char temp;
    char symbols[] = "MICHAEL KEPPLE ";
    initscr();
    curs_set(NO_CURSOR);
    int maxRects = MIN(LINES,COLS)/2;
    for (i=0; i<maxRects; i++)
    {
        temp = symbols[i%NAMELENGTH];
        for (x=0; x<(COLS-i*2); x++)
        {
            mvwaddch(stdscr, i, (x+i), temp);
            mvwaddch(stdscr, ((LINES-1)-i), (x+i), temp);
        }
        for (y=0; y<(LINES-i*2); y++)
        {
            mvwaddch(stdscr, (y+i), i, temp);
            mvwaddch(stdscr, (y+i), ((COLS-1)-i), temp);
        }
        refresh();
        sleep(1);
    }
    getch();
    endwin();
    return 0;
}
