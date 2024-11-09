#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define RAND_RANGE 1024

void array_print(const int *arr, int len) {
    if (!len) {
        printf("Oops... Array is empty\n");
        return;
    }
    for (int i = 0; i < len; ++i) {
        printf("array[%d] = %d\n", i, arr[i]);
    }
}

Err array_append_random(int **arr, int *len) {
    int val = rand() % RAND_RANGE;
    int new_len = *len + 1;
    int *new_arr = realloc(*arr, new_len * sizeof(int));
    if (!new_arr) {
        printf("Failed to allocate memory!\n");
        return ERR_MEM;
    }
    new_arr[new_len - 1] = val;
    *arr = new_arr;
    *len = new_len;
    return ERR_OK;
}