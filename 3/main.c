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
	  print_menu();

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
      	remove_at(&data, &len);
        break;
      case '4':
      	processing_arr(&data, &len);
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
