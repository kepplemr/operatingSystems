/*
 * File:   ring.c
 * Author: Michael Kepple
 * Date:   21 Feb 2013
 * Note:   Input value assumed to be valid.
*/
#include "ring.h"
#define ASCIIOFFSET 48
#define BASE 10

int main(int argc, char* argv[])
{
    int flag = getopt(argc, argv, "s:a:m:");
    int value = ad2b(argv[2]);
    switch (flag)
    {
	case 's':
	    sleep(value);
	    printf("RING!!!");
	    break;
	case 'a':
	    alarmDelay(value);
	    break;
	case 'm':
	    msleepDelay(value);
	    break;
	default:
	    fprintf(stderr, "Usage: ring -s|-a|-m <delay>\n");
	    exit(EXIT_FAILURE);
    }
}

/*
 * Function: ad2b
 * Description: converts ASCII digits into binary/
 * Params: Numeric C string to convert.
 * Returns: Int representation of string param.
 * Modifies: Nothing.
*/
int ad2b(char* value)
{
    int sum = 0, digit = 0;
    char* ascii = value;
    while (*ascii)
    {
	sum *= BASE;
	digit = *ascii++ - ASCIIOFFSET;
	sum += digit;
    }
    return sum;
}
