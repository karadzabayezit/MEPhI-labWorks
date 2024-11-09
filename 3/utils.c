#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int inputF(float *x) {
  char inputValue[20];

	while (1) {
		printf("Gimme x: ");
		if(fgets(inputValue, sizeof(inputValue), stdin) == NULL){
			printf("\n!!!!!!!    EOF    !!!!!!!!!!!!!!\n");
			return EOF;
		};

		char *notNum;

		*x = strtof(inputValue, &notNum);

		if(notNum == inputValue || *notNum != '\n') {
			printf("Incorrect. ");
		} else {
			return 0;
		}
	}
}
int inputInt(int *x) {
  char inputValue[20];

	while (1) {
		printf("Gimme x: ");
		if(fgets(inputValue, sizeof(inputValue), stdin) == NULL){
			printf("\n!!!!!!!    EOF    !!!!!!!!!!!!!!\n");
			return EOF;
		};

		char *notNum;

		long res = strtol(inputValue, &notNum, 10);

		if(notNum == inputValue || *notNum != '\n') {
			printf("Incorrect. ");
		} else {
      *x = (int)res;
			return 0;
		}
	}
}

void array_print(const float *arr, int len) {
  printf("\n");
  if (!len) {
      printf("Oops... Array is empty\n");
      return;
  }
  for (int i = 0; i < len; ++i) {
      printf("Array[%d] = %f\n", i, arr[i]);
  }
  printf("Length: %d\n", len);
}

Err init_array(float **arr, int *len) {
  printf("\nEnter the length: ");
  scanf("%d", len);
  if(*len < 1) {
    printf("Enter the length correctly");
    return ERR_MEM;
  }

  float *new_arr = malloc((*len * sizeof(int)));
  int i = 0;
  do {
    float elem;
    printf("element[%d]/[%d]: ", i+1, *len);
    scanf("%f", &elem);
    new_arr[i] = elem;

    i++;
  } while(i < *len);

  *arr = new_arr;
  printf("Successfully initialized an array!\n");
  return ERR_OK;
};

Err insert_at(float **arr, int *len) {
  int index;
  float value;
  printf("%d", *len);
  if((inputInt(&index) == EOF) || (inputF(&value) == EOF)) {
		return EOF;
	};

  if (index < 0 || index > *len) {
    printf("Index out of length\n");
    return ERR_MEM;
  };
  float *new_arr = realloc(*arr, ((*len + 1) * sizeof(int)));
  for (int i = *len; i > index; i--) {
    new_arr[i] = new_arr[i - 1];
  }
  new_arr[index] = value;
  *arr = new_arr;
  *len = *len + 1;
};