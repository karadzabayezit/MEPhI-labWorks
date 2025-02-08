#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "../include/cars.h"

void parse_arguments(int argc, char *argv[], int *generate, char **input_file, char **output_file) {
	int opt;
	while ((opt  = getopt(argc, argv, "g:i:o:")) != -1) {
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
			default:
				printf("\nUsage: %s\n", argv[0]);
        printf("      [ -g  *n* ]  -  generate *n* random cars optional, but recommended\n");
        printf("      [ -i  input_file ]  -  optional, but recommended\n");
        printf("      [ -o  output_file ]  -  optional, but recommended\n");
				fprintf(stderr, "Read instruction above.\n");
        exit(EXIT_SUCCESS);
		}
	}
}