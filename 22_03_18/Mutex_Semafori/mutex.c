#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



static int a = 0; //risorsa cndivisa dei due thread

void * thread(void* args){
  int b;
  //simulo le tre istruzioni assembler
  b=a;
  sleep(2); //aggiungo la sleep per fare in modo che i due thread leggano a quando è uguale a 0 (dovrebbe essere 4)
  b=b+2;
  a=b;


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

  printf("[MAIN] a=%d\n", a); //Il valore di a è 2 ma dovrebbe essere 4 



  return 0;
}
