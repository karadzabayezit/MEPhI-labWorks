#include <stdio.h>
#include <string.h>


#include "../include/cars.h"

#define INITIAL_ARRAY_SIZE 10

size_t input_cars(Car **cars) {
    size_t capacity = INITIAL_ARRAY_SIZE;
    size_t count = 0;
    *cars = malloc(capacity * sizeof(Car));

    if (!*cars) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    printf("Enter car details (brand, owner_name, mileage). Type 'end' to finish.\n");

    while (1) {
        if (count == capacity) {
            capacity *= 2;
            *cars = realloc(*cars, capacity * sizeof(Car));
            if (!*cars) {
                perror("Failed to reallocate memory");
                exit(EXIT_FAILURE);
            }
        }

        char brand[MAX_BRAND_LENGTH];
        char owner_name[256];
        float mileage;

        printf("Car %zu: ", count + 1);
        if (scanf("%15s", brand) != 1 || strcmp(brand, "end") == 0) {
            break;
        }
        scanf("%255s %f", owner_name, &mileage);

        (*cars)[count].owner_name = strdup(owner_name);
        if (!(*cars)[count].owner_name) {
            perror("Failed to allocate memory for owner_name");
            exit(EXIT_FAILURE);
        }
        strncpy((*cars)[count].brand, brand, MAX_BRAND_LENGTH - 1);
        (*cars)[count].brand[MAX_BRAND_LENGTH - 1] = '\0';
        (*cars)[count].mileage = mileage;
        count++;
    }

    return count;
}
