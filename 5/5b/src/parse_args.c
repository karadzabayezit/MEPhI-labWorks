#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_arguments(int argc, char *argv[], char **input_file, char **output_file, int *sortAlgo, int *sortField, int *asc) {
    for (int i = 1; i < argc; i++) {
      if(strcmp(argv[i], "--input") == 0 || strcmp(argv[i], "-i") == 0 && argv[i+1] != NULL) {
        if((argv[i+1])[0] != '-') {
          *output_file = argv[i+1];
          i++;
        }
      } else if(strcmp(argv[i], "--output") == 0 || strcmp(argv[i], "-o") == 0 && argv[i+1] != NULL) {
        if((argv[i+1])[0] != '-') {
          *output_file = argv[i+1];
          i++;
        }
      } else if(strcmp(argv[i], "--sortType") == 0 || strcmp(argv[i], "-s") == 0 && argv[i+1] != NULL) {
        char *sort = argv[i+1];
        if(strcmp(sort, "gnome") == 0) {
          *sortAlgo = 0;
        } else if(strcmp(sort, "insertion") == 0) {
          *sortAlgo = 1;
        } else if(strcmp(sort, "qsort") == 0) {
          *sortAlgo = 2;
        } else {
          fprintf(stderr, "Usage: %s -s|--sortType [gnome, insertion, qsort] \n", argv[0]);
          exit(EXIT_FAILURE);
          i--;
        }
        i++;
      } else if(strcmp(argv[i], "--field") == 0 || strcmp(argv[i], "-f") == 0 && argv[i+1] != NULL) {
        char *field = argv[i+1];
        if(strcmp(field, "brand") == 0) {
          *sortField = 0;
        } else if(strcmp(field, "owner") == 0) {
          *sortField = 1;
        } else if(strcmp(field, "mileage") == 0) {
          *sortField = 2;
        } else {
          fprintf(stderr, "Usage: %s -f|--field [brand, owner, mileage] \n", argv[0]);
          exit(EXIT_FAILURE);
          i--;
        }
        i++;
      } else if(strcmp(argv[i], "--ascending") == 0 || strcmp(argv[i], "-a") == 0 && argv[i+1] != NULL) {
        char *ascType = argv[i+1];
        if(strcmp(ascType, "asc") == 0) {
          *asc = 0;
        } else if(strcmp(ascType, "desc") == 0) {
          *asc = 1;
        }  else {
          fprintf(stderr, "Usage: %s -a|--ascending [ asc|desc ]\n", argv[0]);
          exit(EXIT_FAILURE);
          i--;
        }
        i++;
      } else if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
        printf("\nUsage: %s\n", argv[0]);
        printf("       [ -i|--input  input_file ]  -  optional, but recommended\n");
        printf("       [ -o|--output  output_file ]  -  optional, but recommended\n");
        printf("       [ -s|--sortType  gnome|insertion|qsort ]  -  optional, GNOME by default\n");
        printf("       [ -f|--field  brand|owner|mileage ]  -  optional, BRAND by default\n");
        printf("       [ -a|--ascending  asc|desc ]  -  optional, ASC by default\n");
        exit(EXIT_SUCCESS);
      } else {
        fprintf(stderr, "Use: %s -h|--help to see what is aviable\n", argv[0]);
        exit(EXIT_FAILURE);
      }
    }
}