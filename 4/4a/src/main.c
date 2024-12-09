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
    if (output != NULL) {
      free(output);
    }
    process_str(input, &output);

    printf("\"%s\" -> \"%s\"\n", input, output);

    free(input);
  }

  free(output);
  rl_clear_history();
  rl_free_line_state();
  rl_cleanup_after_signal();

  return 0;
}
