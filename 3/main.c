#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

int main() {
    srand(time(NULL));
    int *data = NULL;
    int len = 0;
    char option = -1;
    do {
        printf("\n");
        printf("***** MENU *****\n");
        printf("1. Append array with a random integer\n");
        printf("2. Print array\n");
        printf("0. Exit\n");
        printf("\n");
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
            array_append_random(&data, &len);
            array_print(data, len);
            break;
        case '2':
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