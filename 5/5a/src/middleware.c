#include <stdio.h>
#include <string.h>


#include "../include/cars.h"

#define INITIAL_ARRAY_SIZE 10

int input_cars(Car **cars, size_t *count) {
    size_t capacity = INITIAL_ARRAY_SIZE;
    *cars = malloc(capacity * sizeof(Car));

    if (!*cars) {
        printf("Mem allocation failed to cars!");
        return -1;
    }

    printf("Enter car details (brand, owner_name, mileage). Type 'end' to finish.\n");

    while (1) {
        if ((*count) == capacity) {
            capacity *= 2;
            *cars = realloc(*cars, capacity * sizeof(Car));
            if (!*cars) {
                printf("Mem reallocation failed to cars!");
                return -1;
            }
        }

        char brand[MAX_BRAND_LENGTH];
        char owner_name[256];
        float mileage;

        printf("Car %zu: ", (*count) + 1);
        if (scanf("%15s", brand) != 1 || strcmp(brand, "end") == 0) {
            break;
        }
        scanf("%255s %f", owner_name, &mileage);

        (*cars)[(*count)].owner_name = strdup(owner_name);
        if (!(*cars)[(*count)].owner_name) {
            printf("Mem allocation failed to owner!");
            return -1;
        }
        strncpy((*cars)[(*count)].brand, brand, MAX_BRAND_LENGTH - 1);
        (*cars)[(*count)].brand[MAX_BRAND_LENGTH - 1] = '\0';
        (*cars)[(*count)].mileage = mileage;
        (*count)++;
    }

    return 0;
}

int write_cars_to_file(const char *filename, Car *cars, size_t count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file");
        return -1;
    }

    for (size_t i = 0; i < count; i++) {
        fprintf(file, "%s %s %.2f\n", cars[i].brand, cars[i].owner_name, cars[i].mileage);
    }

    fclose(file);
    return 0;
}

int read_cars_from_file(const char *filename, Car **cars, size_t *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file");
        return -1;
    }

    size_t capacity = INITIAL_ARRAY_SIZE;
    *cars = malloc(capacity * sizeof(Car));

    if (!*cars) {
        printf("Mem allocation failed to cars!");
        fclose(file);
        return -1;
    }

    while (!feof(file)) {
        if ((*count) == capacity) {
            capacity *= 2;
            *cars = realloc(*cars, capacity * sizeof(Car));
            if (!*cars) {
                printf("Failed to reallocate memory");
                fclose(file);
                return -1;
            }
        }

        char brand[MAX_BRAND_LENGTH];
        char owner_name[256];
        float mileage;

        if (fscanf(file, "%15s %255s %f", brand, owner_name, &mileage) == 3) {
            (*cars)[(*count)].owner_name = strdup(owner_name);
            if (!(*cars)[(*count)].owner_name) {
                printf("Failed to allocate memory for owner");
                fclose(file);
                return -1;
            }
            strncpy((*cars)[(*count)].brand, brand, MAX_BRAND_LENGTH - 1);
            (*cars)[(*count)].brand[MAX_BRAND_LENGTH - 1] = '\0';
            (*cars)[(*count)].mileage = mileage;
            (*count)++;
        }
    }

    fclose(file);
    return 0;
}
