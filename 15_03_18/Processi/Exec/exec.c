#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

  char* args[] = {"pippo", "pluto", NULL};
  execvp("./exec_2", args);

  printf(">> Prova\n"); //questa pritnf non viene mai stampata perchè viene effettuata la sostituzione del codice

  return 0;
}
