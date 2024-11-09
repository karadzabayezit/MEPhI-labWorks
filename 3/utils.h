#ifndef ARRAY_H
#define ARRAY_H

typedef enum Err {
    ERR_OK = 0,
    ERR_MEM = -1,
} Err;

void array_print(const int *array, int len);
Err array_append_random(int **array, int *len);

#endif