#ifndef ARRAY_H
#define ARRAY_H

typedef enum Err {
  ERR_OK = 0,
  ERR_MEM = -1,
} Err;

void print_menu();
void array_print(const float *array, int len);
int inputInt(int *x);
int init_mem(float **arr,int *mem,  int *len);
Err init_array(float *array, int mem, int *len);
Err insert_at(float *arr, int mem, int *len);
int remove_at(float *arr, int mem, int *len, int index);
int processing_arr(float *arr, int mem, int *len);
#endif
