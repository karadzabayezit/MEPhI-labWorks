#include <stdio.h>
#include <stdlib.h>
// my utility functions and readline
#include "../include/utils.h"
#include "../include/read_line.h"

int main() {
  char *input = NULL;
  char output[1024];

  while ((input = read_line("Введите строку (завершение: Ctrl+D, Ctrl+Z): ")) != NULL) {

    process_str(input, output);

    printf("\"%s\" -> \"%s\"\n", input, output);

    free(input);
  }

  return 0;
}
