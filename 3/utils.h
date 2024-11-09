#ifndef ARRAY_H
#define ARRAY_H

typedef enum Err {
  ERR_OK = 0,
  ERR_MEM = -1,
} Err;

void array_print(const float *array, int len);
Err init_array(float **array, int *len);
Err insert_at(float **arr, int *len);

#endif