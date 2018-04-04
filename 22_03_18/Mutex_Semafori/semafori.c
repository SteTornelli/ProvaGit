#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define N 10

static sem_t sem;
static sem_t sem2;
static int a=0;

//il primo thread incrementa a 100 volte
void * thread1(void* args){

  int i;
  for (i = 0;i < N;i++) {
    a=i;
    printf("[THREAD1] a=%d\n", a);
    sem_post(&sem); //segalo al thread2 che può eseguire
    sem_wait(&sem2); //attendo che il thread2 abbia stampato il valore di 2a (il valore di a corrente)
  }
  pthread_exit((void*)NULL);
}

//il secondo stampa 2*a per ogni valore di a
void * thread2(void* args){
  int i;
  for (i = 0;i < N;i++) {
    sem_wait(&sem); //attendo che thread1 abbia generato a
    printf("[THREAD2] 2a = %d\n", 2*a);
    sem_post(&sem2); //seganlo al thread1 che ho "stampato 2*a" [se commento questo post ho un deadlock]
  }

  pthread_exit((void*)NULL);
}

int main() {


  pthread_t th1, th2;

  //inizializzo i due semafori
  sem_init(&sem, 0, 0);
  sem_init(&sem2, 0, 0);

  pthread_create(&th1, NULL, thread1, NULL);
  pthread_create(&th2, NULL, thread2, NULL);

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);

  //Alla fine di tutto distruggo i semafori
  sem_destroy(&sem);
  sem_destroy(&sem2);

  printf("[MAIN] a=%d\n", a);




  return 0;
}
