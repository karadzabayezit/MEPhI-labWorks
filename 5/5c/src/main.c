#include <stdio.h>
#include <string.h>

#include "../include/middleware.h"
#include "../include/cars.h"
#include "../include/sort.h"
#include "../include/parse_args.h"
#include "../include/generate.h"


int main(int argc, char *argv[]) {
  char *in_file = NULL;
  char *out_file = NULL;
	int generate = 0;
  int sortAlgo = -1; //0 - gnome, 1 - insertion, 2 - qsort
  int sortField = 0; // 0 - brand, 1 - owner, 2 - mileage
  int ascending = 0; // 0- ascending, 1 - descending

	char *txt_files = "txt, csv";
	char *bin_files = "bin, dat";
  parse_arguments(argc, argv, &generate, &in_file, &out_file, &sortAlgo, &sortField, &ascending);

  Car *cars = NULL;
  size_t count = 0;

  if(generate == 0 && in_file != NULL) {
		char* file = get_file_extension(in_file);
		if(file != NULL && strstr(txt_files, file) != NULL) {
    	if(read_cars_from_file(in_file, &cars, &count) != 0) {
      	free_cars(cars, count);
      	return 1;
    	}
		} else if(file != NULL && strstr(bin_files, file) != NULL) {
				if(read_cars_from_binary_file(in_file, &cars, &count) != 0) {
      	free_cars(cars, count);
      	return 1;
    	}
		} else {
			printf("\nUnknown file type\n");
			return 1;
		}
		free(file);
  } else if(generate == 0){
    input_cars(&cars, &count);
  } else {
		generate_cars(&cars, &count, generate);
	}

	if(count > 0 && sortAlgo >= 0) {
		double time = 0;
  	sort(cars, count, sortAlgo, sortField, ascending, &time);
		printf("\nSORTING TIME - %fsec\n", time);
	}


  if (out_file != NULL) {
		char* file = get_file_extension(out_file);
		if(file != NULL && strstr(txt_files, file) != NULL) {
    	if(write_cars_to_file(out_file, cars, count) != 0) {
      	free_cars(cars, count);
      	return 1;
    	} else {
      	printf("\nSuccessfully writed to %s\n", out_file);
    	}
		} else if(file != NULL && strstr(bin_files, file) != NULL) {
			if(write_cars_to_binary_file(out_file, cars, count) != 0) {
      	free_cars(cars, count);
      	return 1;
    	} else {
      	printf("\nSuccessfully writed to %s\n\n", out_file);
    	}
		} else {
			printf("\nUnknown file type\n");
			return 1;
		}
		free(file);
  } else {
    printf("\nCars list:\n");
    print_cars(cars, count);
  }
  free_cars(cars, count);

  return 0;
}
