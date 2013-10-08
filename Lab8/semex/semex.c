//
//  $Id: semex.c,v 1.2 2011/03/24 16:13:42 khj Exp $
//
//     From Real-Time Systems Design and Analysis (3e)
//          Phillip A. Laplante
//          p144-145
//

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/sem.h>

sem_t writer_lock;
sem_t reader_lock;

void read_user(void) {
     /////////

  while (1) {
    sem_wait(&reader_lock);

    printf("In reader task\n");
    sleep(2);                          // simulate read

    sem_post(&writer_lock);

  }
}

void write_user(void) {
     //////////

  while (1) {
    sem_wait(&writer_lock);

    printf("In writer task\n");
    sleep(2);                          // simulate write

    sem_post(&reader_lock);

  }
}



int main() {
    ////

  pthread_t      read_thread;
  pthread_attr_t attribute;

  sem_init(&writer_lock, 0, 1);

  sem_init(&reader_lock, 0, 1);
  sem_wait(&reader_lock);

  pthread_attr_init(&attribute);
  pthread_create(&read_thread, &attribute, (void *) &read_user, NULL);

  write_user();

  return 0;
}

