#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

int main() {
  srand(time(NULL));
  float *data = NULL;
  int mem = 0;
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
        init_mem(&data, &mem, &len);
        break;
      case '2':
        init_array(data, mem, &len);
        break;
      case '3':
        insert_at(data, mem, &len);
        break;
      case '4':
      	int index;
      	printf("Enter the index: ");
      	if(inputInt(&index) == EOF){
      		return EOF;
      	}
      	remove_at(data, mem, &len, index);
        break;
      case '5':
      	processing_arr(data, mem, &len);
        break;
      case '6':
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
