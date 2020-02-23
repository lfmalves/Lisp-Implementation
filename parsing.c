#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"
#include <editline/readline.h> //sudo apt-get install libedit-dev
#include <editline/history.h>

int main(int argc, char** argv) {
  puts("PoorLisp Version 0.0.1");
  puts("Press Ctrl+c to Exit\n");

  while (1) {
    char* input = readline("poorlisp> ");
    add_history(input);
    printf("Spitting back %s\n", input);
    free(input);
  }
  return 0;
}
