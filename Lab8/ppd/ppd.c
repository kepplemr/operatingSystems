/*
 *
 * ppd.c
 *
 * Author: Michael Kepple
 * Date:   2 Apr 2013
 * Description: Program creates two "pseudo periodic" threads. The first will
 *   continuously greet the user ever 300ms;  the second will say "Goodbye!"
 *   every 700ms.
 *
*/
#include "ppd.h"
pthread_mutex_t lock;
pthread_cond_t cond;

/* 
 * Function: printMessage
 * Description: function run by each thread, periodically printing out their
 *   assigned message.
 * Params: Args struct containing message to print and desired delay between
 *   messages.
 * Returns: Nothing (should never return).
 * Modifies: lock
*/
void printMessage(void * arguments)
{
    struct timespec timeToWait;
    struct timeval now;
    Args *passedIn = (Args *)arguments;
    for (;;)
    {
        gettimeofday(&now, NULL);
        int nano = (now.tv_usec*U_IN_NANO + passedIn->delay);
        if (nano > N_IN_SEC)
        {
            timeToWait.tv_sec = now.tv_sec+1;
            timeToWait.tv_nsec = nano - N_IN_SEC;
        }
        else
        {
            timeToWait.tv_sec = now.tv_sec;
            timeToWait.tv_nsec = nano;
        }
        pthread_mutex_lock(&lock);
        pthread_cond_timedwait(&cond, &lock, &timeToWait);
        pthread_mutex_unlock(&lock);
        printf("%s\n", passedIn->msg);
    }
}

int main()
{
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_t hey_thread, bye_thread;
    Args helloArgs, byeArgs;
    strcpy(helloArgs.msg, HEY_MSG);
    strcpy(byeArgs.msg, BYE_MSG);
    helloArgs.delay = HELLO_WAIT;
    byeArgs.delay = BYE_WAIT;
    pthread_create(&hey_thread, NULL, (void*) &printMessage, (void*)&helloArgs);
    pthread_create(&bye_thread, NULL, (void*) &printMessage, (void*)&byeArgs);
    pthread_join(bye_thread, NULL);
}
