#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

  int i;
  for (i = 0;i < argc; i++) {
    printf("exec_2.c - %s\n", argv[i]);
  }

  return 0;
}
