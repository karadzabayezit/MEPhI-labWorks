#include <stdio.h>

#include "../include/middleware.h"
#include "../include/cars.h"
#include "../include/parse_args.h"
#include "../include/generate.h"

int main(int argc, char *argv[]) {
    char *in_file = NULL;
    char *out_file = NULL;
		int generate = 0;

    parse_arguments(argc, argv, &generate, &in_file, &out_file);

    Car *cars = NULL;
    size_t count = 0;

    if(generate == 0 && in_file != NULL) {
      read_cars_from_file(in_file, &cars, &count);
    } else if(generate == 0) {
      input_cars(&cars, &count);
    } else {
			generate_cars(&cars, &count, generate);
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
