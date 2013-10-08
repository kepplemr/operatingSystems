/*
 *
 * magic8.c
 *
 * Author:      Michael Kepple
 * Date:        24 Apr 2013
 * Description: Implementation code for magic8 device driver.
 *
*/
#include <minix/drivers.h>
#include <minix/chardriver.h>
#include <stdio.h>
#include <stdlib.h>
#include <minix/ds.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "magic8.h"

static int magic_open(message *m);
static int magic_close(message *m);
static int magic_ioctl(message *m);
static struct device * magic_prepare(dev_t device);
static int magic_transfer(endpoint_t endpt, int opcode, u64_t position,
	iovec_t *iov, unsigned int nr_req, endpoint_t user_endpt, unsigned int
	flags);
static void sef_local_startup(void);
static int sef_cb_init(int type, sef_init_info_t *info);
static struct chardriver magic_tab =
{
    magic_open,
    magic_close,
    magic_ioctl,
    magic_prepare,
    magic_transfer,
    nop_cleanup,
    nop_alarm,
    nop_cancel,
    nop_select,
    NULL
};
static struct device magic_device;

static int open_counter;

static int magic_open(message *UNUSED(m))
{
    int rand = random() % NUM_RESPONSES;
    char *message;
    if (SEQ == SEQUENTIAL)
        message = answers[open_counter%NUM_RESPONSES];
    else
        message = answers[rand];
    int i=0;
    switch (CASE)
    {
        case ORIGINAL:
            while (message[i] != '\0')
                printf("%c", message[i++]);
            break;
        case UPPER:
            while (message[i] != '\0')
                printf("%c", toupper(message[i++]));
            break;
        case LOWER:
             while (message[i] != '\0')
                 printf("%c", tolower(message[i++]));
    }
    if (STOKE)
        printf("!!!");
    printf("\n");
    open_counter++;
    return OK;
}

static int magic_close(message *UNUSED(m))
{
    return OK;
}

static int magic_ioctl(message *m)
{
    switch (m->TTY_REQUEST)
    {
        case SET_ORIG:
            CASE = ORIGINAL;
            break;
        case SET_UPPER:
            CASE = UPPER;
            break;
        case SET_LOWER:
            CASE = LOWER;
            break;
        case SET_SEQUENTIAL:
            SEQ = SEQUENTIAL;
            break;
        case SET_RANDOM:
            SEQ = RANDOM;
            break;
        case SET_STOKED:
            STOKE = STOKED;
            break;
        case SET_NOT_STOKED:
            STOKE = NOT_STOKED;
            break;
    }
    return OK;
}

static struct device * magic_prepare(dev_t UNUSED(dev))
{
    magic_device.dv_base = make64(0, 0);
    return &magic_device;
}

static int magic_transfer(endpoint_t endpt, int opcode, u64_t position,
    iovec_t *iov, unsigned nr_req, endpoint_t UNUSED(user_endpt),
    unsigned int UNUSED(flags))
{
    return OK;
}

static void sef_local_startup()
{
    sef_setcb_init_fresh(sef_cb_init);
    sef_setcb_init_lu(sef_cb_init);
    sef_setcb_init_restart(sef_cb_init);
    sef_setcb_lu_prepare(sef_cb_lu_prepare_always_ready);
    sef_setcb_lu_state_isvalid(sef_cb_lu_state_isvalid_standard);
    sef_startup();
}

static int sef_cb_init(int type, sef_init_info_t *UNUSED(info))
{
    CASE = ORIGINAL;
    SEQ = SEQUENTIAL;
    STOKE = NOT_STOKED;
    srandom(time(NULL));
    open_counter = 0;
    return OK;
}

int main(void)
{
    sef_local_startup();
    chardriver_task(&magic_tab, CHARDRIVER_SYNC);
    return OK;
}
