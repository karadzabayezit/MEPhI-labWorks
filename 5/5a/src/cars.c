#include <stdio.h>

#include "../include/cars.h"

void print_cars(Car *cars, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%zu: %s, %s, %f\n", i + 1, cars[i].brand, cars[i].owner_name, cars[i].mileage);
    }
    printf("\n");
}

void free_cars(Car *cars, size_t count) {
    for (size_t i = 0; i < count; i++) {
        free(cars[i].owner_name);
        free(cars[i].brand);
    }
    free(cars);
}
