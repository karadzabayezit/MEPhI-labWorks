#include <stdio.h>

#include "../include/middleware.h"
#include "../include/cars.h"
#include "../include/sort.h"

int main(int argc, char *argv[]) {
  char *in_file = NULL;
  char *out_file = NULL;
  int sortAlgo = 0; //0 - gnome, 1 - insertion, 2 - qsort
  int sortField = 0; // 0 - brand, 1 - owner, 2 - mileage
  int ascending = 1; // 1- ascending, 0 - descending

  parse_arguments(argc, argv, &in_file, &out_file, &sortAlgo, &sortField, &ascending);
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
