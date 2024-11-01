#include "./functions.h"

long double getCos(long double radians, int limit) {
	long double numInDegree = 1;
	long double factorial = 1;
	long double res = 1;
	radians = fmod(radians, 2 * M_PI);

	for(int i = 1; i < limit ; i++) {

		numInDegree *= -1 * radians * radians;
		factorial *= (2*i) * (2*i -1);

		res += (numInDegree / factorial);
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
