#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void usr1_handler(int sig)
{

  if (sig== SIGUSR1) {
    printf("Ricevuto SIGUSR1\n");
  }
  else{
    exit(0);
  }
}

int main(int argc, char* argv[]) {

  sighandler_t p;

  p = signal(SIGUSR1, usr1_handler);

  if (p==SIG_ERR) {
    printf("SIGUSR1 non registrato\n");
    exit(-1);
  }

  /*
  p = signal(SIGTERM, usr1_handler);

  if (p==SIG_ERR) {
    printf("SIGUSR1 non registrato\n");
    exit(-1);
  }
  */

  while (1){};

  return 0;
}
