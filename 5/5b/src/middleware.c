#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "../include/cars.h"
#include "../include/sort.h"
#include "../include/parse_args.h"

char* get_file_extension(char* file_name) {
  char* ext = calloc(6, sizeof(char));
  if (!ext) {
    perror("Failed to allocate memory");
    return NULL;
  }

  char* ptr = strrchr(file_name, '.');
  if (!ptr || ptr == file_name) {
    return NULL;
  }

  for (int i = 1; i < 6 && ptr[i] != '\0'; i++) {
    ext[i-1] = ptr[i];
  }

  return ext;
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
    (*cars)[i].owner = owner;
    (*cars)[i].mileage = milleage;

    i++;
  }

  return 0;
}

int write_cars_to_file(const char *filename, Car *cars, size_t count) {
  FILE *file = fopen(filename, "a");

  if (!file) {
    printf("Failed to open file\n");
    return -1;
  }

  for (size_t i = 0; i < count; i++) {
    fprintf(file, "%s,%s,%.2f\n", cars[i].brand, cars[i].owner, cars[i].mileage);
  }

  fclose(file);
  return 0;
}

int write_cars_to_binary_file(const char *filename, Car *cars, size_t count) {
  FILE *file = fopen(filename, "wb");

  if (!file) {
    perror("Failed to open file");
    return -1;
  }

  for (int i = 0; i < count; i++) {
    int brand_len = strlen(cars[i].brand);
    int owner_len = strlen(cars[i].owner);
    fwrite(&brand_len, sizeof(int), 1, file);
    fwrite(cars[i].brand, sizeof(char), brand_len, file);

    fwrite(&owner_len, sizeof(int), 1, file);
    fwrite(cars[i].owner, sizeof(char), owner_len, file);

    fwrite(&cars[i].mileage, sizeof(float), 1, file);
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
    char *owner = strtok(NULL, ",");
    char *mileage_str = strtok(NULL, ",");

    if (brand && owner && mileage_str) {
      (*cars)[i].brand = strdup(brand);
      if (!(*cars)[i].brand) {
        printf("Failed to allocate memory for brand\n");
        free(line);
        fclose(file);
        return -1;
      }
      (*cars)[i].owner = strdup(owner);
      if (!(*cars)[i].owner) {
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

int read_cars_from_binary_file(const char *filename, Car **cars, size_t *count) {
  FILE *file = fopen(filename, "rb");

  if (!file) {
    perror("Failed to open file");
    return -1;
  }

  size_t capacity = 10;
  *cars = malloc(capacity * sizeof(Car));

  if (!*cars) {
    perror("Memory allocation failed for cars");
    fclose(file);
    return -1;
  }

  size_t i = 0;

  while (1) {
    if (i == capacity) {
      capacity *= 2;
      Car *temp = realloc(*cars, capacity * sizeof(Car));
      if (!temp) {
        perror("Failed to reallocate memory");
        fclose(file);
        return -1;
      }
      *cars = temp;
    }
    int brand_len, owner_len;
    if (fread(&brand_len, sizeof(int), 1, file) != 1) break;
    (*cars)[i].brand = malloc(brand_len + 1);

    if (!(*cars)[i].brand) {
      perror("Failed to allocate memory for brand");
      fclose(file);
      return -1;
    }
    if (fread((*cars)[i].brand, sizeof(char), brand_len, file) != brand_len) {
      perror("Failed to read brand");
      free((*cars)[i].brand);
      fclose(file);
      return -1;
    }
    (*cars)[i].brand[brand_len] = '\0';

    if (fread(&owner_len, sizeof(int), 1, file) != 1) break;
    (*cars)[i].owner = malloc(owner_len + 1);

    if (!(*cars)[i].owner) {
      perror("Failed to allocate memory for owner");
      free((*cars)[i].brand);
      fclose(file);
      return -1;
    }

    if (fread((*cars)[i].owner, sizeof(char), owner_len, file) != owner_len) {
      perror("Failed to read owner");
      free((*cars)[i].brand);
      free((*cars)[i].owner);
      fclose(file);
      return -1;
    }
    (*cars)[i].owner[owner_len] = '\0';

    if (fread(&(*cars)[i].mileage, sizeof(float), 1, file) != 1) break;
    i++;
  }

  *count = i;
  fclose(file);
  return 0;
}
