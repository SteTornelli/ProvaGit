//Uno
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

  pid_t pid;

  pid=fork();

  if (pid==0) {
    sleep(10);
    printf(">> Processo Figlio: %d\n  >> PID Padre: %d\n", (int)getpid(), (int)getppid());
  }
  else{
    //sleep(1);
    printf(">> Processo Padre: %d\n  >> PID Padre: %d\n", (int)getpid(), (int)getppid());
  }



  return 0;
}
