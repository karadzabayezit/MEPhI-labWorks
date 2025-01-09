#include <stdlib.h>

#include "../include/cars.h"

void parse_arguments(int argc, char *argv[], char **input_file,
                     char **output_file);
int input_cars(Car **cars, size_t *count);
int write_cars_to_file(const char *filename, Car *cars, size_t count);
int read_cars_from_file(const char *filename, Car **cars, size_t *count);
