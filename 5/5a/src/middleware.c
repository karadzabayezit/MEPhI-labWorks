#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "../include/cars.h"

void parse_arguments(int argc, char *argv[], char **input_file, char **output_file) {
    int opt;
    *input_file = NULL;
    *output_file = NULL;

    for (int i = 1; i < argc; i++) {
      if(strcmp(argv[i], "--input") == 0 || strcmp(argv[i], "-i") == 0) {
        *input_file = argv[i+1];
        i++;
      } else if(strcmp(argv[i], "--output") == 0 || strcmp(argv[i], "-o") == 0) {
        *output_file = argv[i+1];
        i++;
      } else if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h")) {
        printf("Usage: %s [-i input_file] [-o output_file]\n", argv[0]);
        exit(EXIT_SUCCESS);
      } else {
        fprintf(stderr, "Usage: %s [-i input_file] [-o output_file]\n", argv[0]);
        exit(EXIT_FAILURE);
      }
    }
}

int input_cars(Car **cars, size_t *count) {
    char *input = NULL;
    int i = 0;
    int tmp_count = 0;
    printf("How many cars will be? "); scanf("%d", &tmp_count);
    *cars = malloc(tmp_count * sizeof(Car));
    *count = tmp_count;
    while(i != tmp_count) {
      printf("\n---Car %d---\n", i+1);
      char* brand = readline("Brand: ");
      char* owner = readline("Owner: ");
      float milleage = -1;
      printf("Milleage: "); scanf("%f", &milleage);

      if(milleage ==  -1|| brand == NULL || owner == NULL) {
        printf("Failed to get parts of car!");
        return 1;
      }

      (*cars)[i].brand = brand;
      (*cars)[i].owner_name = owner;
      (*cars)[i].mileage = milleage;

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
        fprintf(file, "%s,%s,%.2f\n", cars[i].brand, cars[i].owner_name, cars[i].mileage);
    }

    fclose(file);
    return 0;
}


int read_cars_from_file(const char *filename, Car **cars, size_t *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file\n");
        return -1;
    }

    size_t capacity = 10;
    *cars = malloc(capacity * sizeof(Car));
    if (!*cars) {
        printf("Memory allocation failed for cars!\n");
        fclose(file);
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    int i = 0;

    while (getline(&line, &len, file) != -1) {
      line[strcspn(line, "\n")] = 0;

      if (i == capacity) {
        capacity *= 2;
        Car *temp = realloc(*cars, capacity * sizeof(Car));
        if (!temp) {
          perror("Failed to reallocate memory");
          free(line);
          fclose(file);
          return -1;
        }
          *cars = temp;
      }

      char *brand = strtok(line, ",");
      char *owner_name = strtok(NULL, ",");
      char *mileage_str = strtok(NULL, ",");


      if (brand && owner_name && mileage_str) {
        (*cars)[i].brand = strdup(brand);
        if (!(*cars)[i].brand) {
          printf("Failed to allocate memory for brand\n");
          free(line);
          fclose(file);
          return -1;
        }

        (*cars)[i].owner_name = strdup(owner_name);
        if (!(*cars)[i].owner_name) {
          printf("Failed to allocate memory for owner\n");
          free((*cars)[i].brand);
          free(line);
          fclose(file);
          return -1;
          }

          (*cars)[i].mileage = atof(mileage_str);
          (i)++;
      } else {
        fprintf(stderr, "Invalid line format: %s\n", line);
      }

    }
    *count = i;
    free(line);
    fclose(file);
    return 0;
}
