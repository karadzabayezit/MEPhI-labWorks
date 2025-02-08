#include <stdlib.h>

#include "../include/cars.h"

int input_cars(Car **cars, size_t *count);
int write_cars_to_file(const char *filename, Car *cars, size_t count);
int write_cars_to_binary_file(const char *filename, Car *cars, size_t count);
int read_cars_from_file(const char *filename, Car **cars, size_t *count);
int read_cars_from_binary_file(const char *filename, Car **cars, size_t *count);
char* get_file_extension(char* file_name);
