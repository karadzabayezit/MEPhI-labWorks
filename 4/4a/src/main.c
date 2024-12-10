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
  char *output = NULL;

  while ((input = readline("Введите строку (завершение: Ctrl+D / Ctrl+Z): ")) != NULL) {

    process_str(input, &output);

    printf("\"%s\" -> \"%s\"\n", input, output);

    free(input);
    free(output);
  }

  return 0;
}
