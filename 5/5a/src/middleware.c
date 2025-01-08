#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "../include/cars.h"

#define INITIAL_ARRAY_SIZE 10

int input_cars(Car **cars, size_t *count) {
    char *input = NULL;
    int i = 0;
    int tmp_count = 0;
    printf("How many cars will be? "); scanf("%d", &tmp_count);
    *cars = malloc(tmp_count * sizeof(Car));
    *count = tmp_count;
    printf("Template: Brand, Owner, Milleage");
    while(i != tmp_count) {
      printf("\nCar %d \n", i+1);
      char* brand = readline("Brand: ");
      char* owner = readline("Owner: ");
      float milleage = -1;
      printf("Milleage: "); scanf("%f", &milleage);

      if(milleage ==  -1|| brand == NULL || owner == NULL) {
        printf("Failed to get parts of car!");
        return 1;
      }


      (*cars)[i].owner_name = owner;
      (*cars)[i].brand = brand;
      (*cars)[i].mileage = milleage;
      printf("%s %s %f", (*cars)[i].brand, (*cars)[i].owner_name, (*cars)[i].mileage);

      i++;
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
