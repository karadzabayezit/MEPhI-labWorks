#include <stdio.h>

#include "../include/middleware.h"
#include "../include/cars.h"

int main(int argc, char *argv[]) {
    char *in_file = NULL;
    char *out_file = NULL;

    Car *cars = NULL;
    size_t count = 0;

    count = input_cars(&cars);

    printf("\nCars list:\n");
    print_cars(cars, count);

    free_cars(cars, count);
    return 0;
}
