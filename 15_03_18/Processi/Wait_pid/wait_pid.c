#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define P 10

int main() {

  int i, status;
  pid_t pid[P];
  pid_t wpid;

  printf("PADRE PID %d\n", (int)getpid());

  for (i=0; i < P; i++)
  {
    wpid = fork();

    if (wpid==0) {
      printf("FIGLIO PID %d\n", (int)getpid());
      sleep(3);

      exit(i);
    }
    else{
      pid[i] = wpid;
    }
  }

  printf("PADRE Aspetto il figlio %d\n", (int)pid[4]);
  wpid=waitpid(pid[4], &status, 0);

  printf("PADRE Terminato %d con status %d\n", (int)wpid, status);

  printf("PADRE Aspetto gli altri figli\n");
  for (i = 0; i < P-1; i++)
  {
    wpid=wait(&status);
    printf("PADRE Terminato %d con status %d\n", (int)wpid, status);
  }

  exit(EXIT_SUCCESS);

  //return 0;
}
