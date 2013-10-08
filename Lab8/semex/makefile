#
# Makefile for semex
# Lab08 Assignment 4 - yes, you can determine which printf() will be executed
#   first. Even though the reader thread is spawned before the write_user 
#   function is called (could lead to non-deterministic outcome), the 
#   reader_lock semaphore is locked until write_user completes, so write_user
#   will always get 'first print'.
# Author: Michael Kepple
# Date:   02 Apr 2013
#
all: semex.c
	gcc semex.c -lpthread -o semex

clean: 
	rm -rf *o semex
