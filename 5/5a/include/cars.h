#include <stdlib.h>

#ifndef CARS
#define CARS

typedef struct {
  char *brand;
  char *owner_name;
  float mileage;
} Car;

void print_cars(Car *cars, size_t count);
void free_cars(Car *cars, size_t count);

#endif
