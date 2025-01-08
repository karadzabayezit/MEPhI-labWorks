#include <stdlib.h>

#define MAX_BRAND_LENGTH 128
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
