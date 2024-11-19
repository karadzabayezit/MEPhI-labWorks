#include "./functions.h"

long double getCos(long double radians, int limit) {
	long double res = 1;
	long double term = 1;
	
	radians = fmod(radians, 2 * M_PI);
	
	long double numInDegree = -1 * radians * radians;

	for(int i = 1; i < limit ; i++) {

		term *= numInDegree / (2 * i * (2*i -1));

		if(fabsl(term) < 1e-15) break;
		
		res += term;
	}
	return res;
}

int inputX(long double *x) {
	char inputValue[20];


	while (1) {
		printf("Gimme x: ");
		if(fgets(inputValue, sizeof(inputValue), stdin) == NULL){
			printf("\n!!!!!!!    EOF    !!!!!!!!!!!!!!\n");
			return EOF;
		};

		char *notNum;

		*x = strtold(inputValue, &notNum);

		if(notNum == inputValue || *notNum != '\n') {
			printf("Incorrect. ");
		} else {
			return 0;
		}
	}
}

int inputLimit(int *limit) {
	char inputValue[20];

	while (1) {
		printf("Gimme limit: ");
		if(fgets(inputValue, sizeof(inputValue), stdin) == NULL){
			printf("\n!!!!!!!    EOF    !!!!!!!!!!!!!!\n");
			return EOF;
		};

		char *notNum;

		*limit = strtol(inputValue, &notNum, 10);

		if(notNum == inputValue || *notNum != '\n') {
			printf("Incorrect. ");
		} else {
			return 0;
		}
	}
}
