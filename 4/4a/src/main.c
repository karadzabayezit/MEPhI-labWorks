#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// readline
#include <readline/readline.h>
#include <readline/history.h>
// my utility functions
#include "../include/utils.h"

int main() {
  char *input = NULL;
  char output[1024];

  while ((input = readline("Введите строку (завершение: Ctrl+D / Ctrl+Z): ")) != NULL) {

    printf("\"%s\"\n", input);

    process_str(input, output);

    printf("\"%s\" -> \"%s\"\n", input, output);

    free(input);
  }

  return 0;
}
