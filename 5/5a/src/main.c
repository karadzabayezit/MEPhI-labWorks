#include <stdio.h>

#include "../include/middleware.h"
#include "../include/cars.h"

int main(int argc, char *argv[]) {
    char *in_file = NULL;
    char *out_file = NULL;

    parse_arguments(argc, argv, &in_file, &out_file);

    Car *cars = NULL;
    size_t count = 0;

    if(in_file != NULL) {
      read_cars_from_file(in_file, &cars, &count);
    } else {
      input_cars(&cars, &count);
    }

    if (out_file != NULL) {
      if(write_cars_to_file(out_file, cars, count) != 0) {
        free_cars(cars, count);
        return 1;
      } else {
        printf("\nSuccessfully writed to %s\n", out_file);
      }
    } else {
      printf("\nCars list:\n");
      print_cars(cars, count);
    }

    free_cars(cars, count);
    return 0;
}
