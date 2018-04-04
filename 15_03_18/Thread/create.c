#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thread1(void * args){

  printf(">> [TH1] eseguito\n");

  pthread_exit(0);
}

int main() {

  pthread_t th1;

  pthread_create(&th1, NULL, thread1, NULL);

  pthread_join(th1, NULL);
  exit(0);
}
