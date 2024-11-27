#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void print_menu() {
    printf("\n");
    printf("|****************** MENU ****************|\n");
    printf("|1. Initialize a memory.                 |\n");
    printf("|2. Initialize an array.                 |\n");
    printf("|3. Paste to array by index.             |\n");
    printf("|4. Removing element from array by index.|\n");
    printf("|5. Individual task.                     |\n");
    printf("|6. Print array.                         |\n");
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


int init_mem(float **arr,int *mem,  int *len) {
	int size;
	printf("Enter the size of array: ");
	if(inputInt(&size) == EOF) {
		return EOF;
	}
	*mem = size;
	if(*len < 1) {
		*arr = malloc(size * sizeof(float));
	} else {
		*arr = realloc(*arr, (size * sizeof(float)));
		if(size < *len) {
			*len = size;
		}
	}	

	return 0;
};

// int checkMem(int index, int mem) {
// 	
// }


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

Err init_array(float *arr, int mem, int *len) {
  printf("\nEnter the length: ");

  scanf("%d", len);
  if(*len > mem) {
  	printf("Length out of memory. Increase the mem first!");
  	return ERR_MEM;
  }
  if(*len < 1) {
    printf("Enter the length correctly");
    return ERR_MEM;
  }

  
  int i = 0;
  do {
    float elem;
    printf("element[%d]/[%d]: ", i+1, *len);
    if(inputF(&elem) == EOF) {
    	return EOF;
    }
    arr[i] = elem;

    i++;
  } while(i < *len);
  
  printf("Successfully initialized an array!\n");
  return ERR_OK;
};



Err insert_at(float *arr, int mem, int *len) {
  if(!(*len)) {
  	printf("Oops... Array is empty!");
  	return ERR_MEM;
  }
  if(mem == *len || mem < *len) {
  	printf("Increase mem!!!");
  	return 1;
  }
  int index;
  float value;

	printf("Enter index: ");
	if(inputInt(&index) == EOF) {
		return EOF;
	}
	if (index < 0) {
	    printf("Index out of length\n");
	    return ERR_MEM;
	};
	if(index > *len+1) {
		index = *len;
	}
	if(index+1 > mem) {
  		printf("Length out of memory. Increase the mem first!");
  		return ERR_MEM;
	}
	
	printf("Enter Value: ");
	
  	if(inputF(&value) == EOF) {
		return EOF;
	};
	
  	for (int i = *len; i > index; i--) {
    	arr[i] = arr[i - 1];
  	}

  	arr[index] = value;
  	*len = *len + 1;
  	return 0;
};


int remove_at(float *arr, int mem, int *len, int index) {
    if(!(*len)) {
  	  printf("Oops... Array is empty!");
  	  return ERR_MEM;
    }
	
	if (index < 0) {
    	printf("Index out of length\n");
    	return -1;
  	};
  	if(index > *len+1) {
  			index = *len;
  	}

	for(int i = index; i < *len-1; i++) {
		arr[i] = arr[i+1];
	}

	arr[*len-1] = 0;
	(*len)--;
	return 0;
}

int processing_arr(float *arr, int mem, int *len) {
	printf("%d - LEN\n", *len);
	if(!(*len)) {
	  	printf("Oops... Array is empty!");
	  	return ERR_MEM;
	}
	
	float average = 0;
	for(int i = 0; i < *len; i++) {
		average += arr[i];
	}
	average = average / *len;

	printf("Average: %f\n", average);

	float *new_arr = malloc(*len * sizeof(float));
	int count = 0;
	int i = 0;
	while(i < *len) {
		new_arr[i] = arr[i] - average;
		printf("new_arr[%d] - %f\n", i, new_arr[i]);
		printf("%d INDEX\n", i);
		if(arr[i] > average) {
			remove_at(arr, mem, len, i);
			(*len)++;
			count++;
			i--;
		}
		i++;
	}
	

	free(new_arr);
	
	*len = *len - count;
	return 0;
}
