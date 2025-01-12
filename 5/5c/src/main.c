#include <stdio.h>
#include <string.h>

#include "../include/middleware.h"
#include "../include/cars.h"
#include "../include/sort.h"


int main(int argc, char *argv[]) {
  char *in_file = NULL;
  char *out_file = NULL;
  int sortAlgo = 0; //0 - gnome, 1 - insertion, 2 - qsort
  int sortField = 0; // 0 - brand, 1 - owner, 2 - mileage
  int ascending = 0; // 0- ascending, 1 - descending

	char *txt_files = "txt, csv";
	char *bin_files = "bin dat";
  parse_arguments(argc, argv, &in_file, &out_file, &sortAlgo, &sortField, &ascending);

  Car *cars = NULL;
  size_t count = 0;
	printf("\n%s\n\n", in_file);

  if(in_file != NULL) {
		char* file = get_file_extension(in_file);
		if(strstr(txt_files, file) != NULL) {
    	if(read_cars_from_file(in_file, &cars, &count) != 0) {
      	free_cars(cars, count);
      	return 1;
    	}
		} else if(strstr(bin_files, file) != NULL) {
				if(read_cars_from_binary_file(in_file, &cars, &count) != 0) {
      	free_cars(cars, count);
      	return 1;
    	}
		}
  } else {
    input_cars(&cars, &count);
  }

	double time = 0;
  sort(cars, count, sortAlgo, sortField, ascending, &time);
	printf("\nSORTING TIME - %f\sec\n", time);

  if (out_file != NULL) {
		char* file = get_file_extension(out_file);
		if(strstr(txt_files, file) != NULL) {
    	if(write_cars_to_file(out_file, cars, count) != 0) {
      	free_cars(cars, count);
      	return 1;
    	} else {
      	printf("\nSuccessfully writed to %s\n", out_file);
    	}
		} else if(strstr(bin_files, file) != NULL) {
			if(write_cars_to_binary_file(out_file, cars, count) != 0) {
      	free_cars(cars, count);
      	return 1;
    	} else {
      	printf("\nSuccessfully writed to %s\n", out_file);
    	}
		}
  } else {
    printf("\nCars list:\n");
    print_cars(cars, count);
  }

  free_cars(cars, count);

  return 0;
}


