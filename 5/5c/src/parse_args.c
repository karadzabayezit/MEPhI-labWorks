#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

void parse_arguments(int argc, char *argv[], int *generate, char **input_file, char **output_file, int *sortAlgo, int *sortField, int *asc) {
	int opt;
	while ((opt  = getopt(argc, argv, "g:i:o:s:f:a:h")) != -1) {
		switch (opt) {
			case 'g':
				if (optarg[0] == '-') {
          fprintf(stderr, "Error: After -g must be a number\n");
          exit(EXIT_FAILURE);
        }
				char *ptr = '\0';
				int temp = strtol(optarg, &ptr, 10);
				if(*ptr != '\0' || temp <= 0) {
					fprintf(stderr, "Error: After -g must be a number\n");
					exit(EXIT_FAILURE);
				}
				*generate = temp;
				break;
			case 'i':
				if (optarg[0] == '-') {
          fprintf(stderr, "Error: No input file after -i\n");
          exit(EXIT_FAILURE);
        }
				*input_file = optarg;
				break;
			case 'o':
				if (optarg[0] == '-') {
          fprintf(stderr, "Error: No input file after -o\n");
          exit(EXIT_FAILURE);
        }
				*output_file = optarg;
				break;
			case 's':
				if(strcmp(optarg, "gnome") == 0) {
					*sortAlgo = 0;
				} else if(strcmp(optarg, "insertion") == 0) {
					*sortAlgo = 1;
				} else if(strcmp(optarg, "qsort") == 0) {
					*sortAlgo = 2;
				} else {
					fprintf(stderr, "Usage: %s -s [gnome, insertion, qsort] \n", argv[0]);
					exit(EXIT_FAILURE);
				}
				break;
			case 'f':
				if(strcmp(optarg, "brand") == 0) {
					*sortField = 0;
				} else if(strcmp(optarg, "owner") == 0) {
					*sortField = 1;
				} else if(strcmp(optarg, "mileage") == 0) {
					*sortField = 2;
				} else {
					fprintf(stderr, "Usage: %s -f [brand, owner, mileage] \n", argv[0]);
					exit(EXIT_FAILURE);
				}
				break;
			case 'a':
				if(strcmp(optarg, "asc") == 0) {
					*asc = 0;
				} else if(strcmp(optarg, "desc") == 0) {
					*asc = 1;
				} else {
					fprintf(stderr, "Usage: %s -a [asc, desc] \n", argv[0]);
					exit(EXIT_FAILURE);
				}
				break;
			case 'h':
				printf("\nUsage: %s\n", argv[0]);
        printf("      [ -g  *n* ]  -  generate *n* random cars optional, but recommended\n");
        printf("      [ -i  input_file ]  -  optional, but recommended\n");
        printf("      [ -o  output_file ]  -  optional, but recommended\n");
        printf("      [ -s  gnome|insertion|qsort ]  -  optional, GNOME by default\n");
        printf("      [ -f  brand|owner|mileage ]  -  optional, BRAND by default\n");
        printf("      [ -a  asc|desc ]  -  optional, ASC by default\n");
				fprintf(stderr, "Read instruction above.\n");
        exit(EXIT_SUCCESS);
			default:
				printf("\nUsage: %s\n", argv[0]);
        printf("      [ -g  *n* ]  -  generate *n* random cars optional, but recommended\n");
        printf("      [ -i  input_file ]  -  optional, but recommended\n");
        printf("      [ -o  output_file ]  -  optional, but recommended\n");
        printf("      [ -s  gnome|insertion|qsort ]  -  optional, GNOME by default\n");
        printf("      [ -f  brand|owner|mileage ]  -  optional, BRAND by default\n");
        printf("      [ -a  asc|desc ]  -  optional, ASC by default\n");
				fprintf(stderr, "Read instruction above.\n");
        exit(EXIT_SUCCESS);
		}
	}
}