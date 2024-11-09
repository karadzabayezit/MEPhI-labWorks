#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

int main() {
  srand(time(NULL));
  float *data = NULL;
  int len = 0;
  char option = -1;

  do {
    printf("\n");
    printf("|****************** MENU ****************|\n");
    printf("|1. Initialize an array.                 |\n");
    printf("|2. Paste to array by index.             |\n");
    printf("|3. Removing element from array by index.|\n");
    printf("|4. Individual task.                     |\n");
    printf("|5. Print array.                         |\n");
    printf("|0.(Ctrl+D). Exit.                       |\n");
    printf("|****************************************|\n");
    printf("|Choose one option: ");

    int r = scanf(" %c", &option);

    if (r == EOF) {
        free(data);
        return 0;
    }

    switch (option) {
      case '0':
        printf("Exiting...\n");
        break;
      case '1':
        init_array(&data, &len);
        break;
      case '2':
        insert_at(&data, &len);
        break;
      case '3':
        break;
      case '4':
        break;
      case '5':
        array_print(data, len);
        break;
      default:
        printf("Wrong input!\n");
        break;
    }
  } while (option != '0');

  free(data);

  return 0;
}