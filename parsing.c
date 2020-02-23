#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"
#include <editline/readline.h> //sudo apt-get install libedit-dev
#include <editline/history.h>

int main(int argc, char** argv) {
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr = mpc_new("expr");
  mpc_parser_t* Poorlisp = mpc_new("poorlisp");

  mpca_lang(MPCA_LANG_DEFAULT,
  "                                                     \
    number   : /-?[0-9]+/ ;                             \
    operator : '+' | '-' | '*' | '/' ;                  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
  ",
            Number, Operator, Expr, Poorlisp);

  puts("PoorLisp Version 0.0.1");
  puts("Press Ctrl+c to Exit\n");

  while (1) {
    char* input = readline("poorlisp> ");
    add_history(input);
    printf("Spitting back %s\n", input);
    free(input);
  }

  mpc_cleanup(4, Number, Operator, Expr, Poorlisp);
  return 0;
}
