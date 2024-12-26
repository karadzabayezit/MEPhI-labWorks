#include <stdio.h>

#include "../include/middleware.h"
#include "../include/cars.h"

int main(int argc, char *argv[]) {
    char *in_file = NULL;
    char *out_file = NULL;

    Car *cars = NULL;
    size_t count = 0;

    if(in_file) {
      read_cars_from_file(in_file, &cars);
    } else {
      input_cars(&cars, &count);
    }

    printf("\nCars list:\n");
    print_cars(cars, count);

    if (out_file) {
        if(write_cars_to_file(out_file, cars, count) != 0) {
          free_cars(cars, count);
          return 1;
        }
    }

    free_cars(cars, count);
    return 0;
}
