#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void print_menu() {
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
}

int inputF(float *x) {
	float num;
	while(1) {
		int res = scanf("%f", &num);
		if(res == EOF) {
			return EOF;
		}
		if(res != 1) {
			printf("incorrect input, try again: ");
			while(getchar() != '\n');
		} else {
			*x = num;
			return 0;
		}
	}
}
int inputInt(int *x) {
	int num;
	while(1) {
		int res = scanf("%d", &num);
		if(res == EOF) {
			return EOF;
		}
		if(res != 1) {
			printf("incorrect input, try again: ");
			while(getchar() != '\n');
		} else {
			*x = num;
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
  free(*arr);
  *arr = new_arr;
  printf("Successfully initialized an array!\n");
  return ERR_OK;
};



Err insert_at(float **arr, int *len) {
  int index;
  float value;

	printf("Enter index: ");
	if(inputInt(&index) == EOF) {
		return EOF;
	}
	
	printf("Enter Value: ");
  	if(inputF(&value) == EOF) {
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


int remove_at(float **arr, int *len) {
	int index;

	printf("Enter index: ");
	if(inputInt(&index) == EOF) {
		return EOF;
	}
	if (index < 0 || index > *len) {
    	printf("Index out of length\n");
    	return -1;
  	};

	for(int i = index; i < *len-1; i++) {
		(*arr)[i] = (*arr)[i+1];
	}

	*arr = realloc(*arr, ((*len - 1) * sizeof(float)));
	(*len)--;
	return 0;
}

int processing_arr(float **arr, int *len) {
	float average = 0;
	for(int i = 0; i < *len; i++) {
		average += (*arr)[i];
	}
	average = average / *len;

	printf("Average: %f\n", average);

	float *new_arr = malloc(*len * sizeof(float));
	int count = 0;
	for(int i = 0; i < *len; i++) {
		new_arr[i] = (*arr)[i] - average;
		printf("new_arr[%d] - %f\n", i, new_arr[i]);
		if((*arr)[i] <= average) {
			count++;
		}
	}

	float *new_arr_without = malloc(count * sizeof(float));
	int index = 0;
	for(int i = 0; i < *len; i++) {
		if((*arr)[i] <= average) {
			new_arr_without[index] = (*arr)[i];
			index++;
		}
	}	

	free(*arr);
	
	*len = count;
	*arr = new_arr_without;

	free(new_arr);
	return 0;
}
