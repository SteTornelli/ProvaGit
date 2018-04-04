#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



static int a = 0; //risorsa cndivisa dei due thread

static pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;


void * thread(void* args){
  int b;
  pthread_mutex_lock(&mutex); //aggiungo i lock e unlock per garantire l'atomicità
  //simulo le tre istruzioni assembler
  b=a;
  sleep(2);
  b=b+2;
  a=b;

  pthread_mutex_unlock(&mutex);
  printf("[THREAD] a=%d\n", a);
  pthread_exit((void*)NULL);
}
int main() {

  //creiamo due thread che accedono alla stessa risorsa e garantiamo la mutua esclusione
  pthread_t th1, th2;

  pthread_create(&th1, NULL, thread, NULL);
  pthread_create(&th2, NULL, thread, NULL);

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);

  printf("[MAIN] a=%d\n", a);



  return 0;
}
