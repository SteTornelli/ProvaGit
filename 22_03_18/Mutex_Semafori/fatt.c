#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int fatt(int n){
  if (n <= 0)
    return 1;
  return n*fatt(n-1);

}

void* fatt_th(void * args){

  static int f;

  int n = *((int*)args);

  f = fatt(n);

  printf("[TH] fatt(%d) = %d\n", n, f);

  pthread_exit((void *) &f);

}

int main() {
  //int arg, ret;
  int arg, f;
  void* ret = (void*) &f;
  pthread_t tid;

  arg=5;

  pthread_create(&tid, NULL, fatt_th, (void*)&arg);
  pthread_join(tid, &ret);

  f = *((int *)&ret);
  printf("[MAIN] fatt(%d) = %d\n", arg, f); //??????

  return 0;
}
