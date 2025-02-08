#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cars.h"

const char *brands[20] = {"Toyota", "BMW", "Audi", "Ford", "Honda", "Nissan", "Hyundai", "Kia", "Mazda", "Subaru", "Volkswagen", "Mercedes-Benz", "Tesla", "Lamborghini", "Ferrari", "Porsche", "Mclaren", "Bugatti", "Lexus", "Acura"};
const char *owners[20] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Henry", "Isabella", "Jack", "Lucas", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Riley", "Samuel", "Sophia", "Taylor"};

int generate_cars(Car **cars, size_t *count, int generate) {

	*cars = malloc(generate * sizeof(Car));

	if (!*cars) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    return 1;
  }

	for(int i = 0; i < generate; i++) {
		(*cars)[i].brand = strdup(brands[rand() % 20]);
		(*cars)[i].owner = strdup(owners[rand() % 20]);
		(*cars)[i].mileage = rand() % 200000;
	}
	*count = generate;
	return 0;
}