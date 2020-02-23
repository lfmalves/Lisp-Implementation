#include <stdio.h>

static char input[2048];

int main(int argc, char** argv) {
  puts("PoorLisp Version 0.0.1");
  puts("Press Ctrl+c to Exit\n");

  while (1) {
    fputs("poorlisp> ", stdout);
    fgets(input, 2048, stdin);
    printf("Spitting back %s", input);
  }
  return 0;
}
