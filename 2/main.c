#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inputX(long double *x);
int inputLimit(int *limit);

int main() {
	long double x;
	int limit;
	
	if((inputX(&x) == EOF) || (inputLimit(&limit) == EOF)) {
		return 0;
	};

	x = x / 2;
	long double numInDegree = 1;
	long double factorial = 1;
	long double res = 1;

	for(int i = 1; i < limit ; i++) {
		
		numInDegree *= -1 * x * x;
		factorial *= (2*i) * (2*i -1);

		res += (numInDegree / factorial);
	}


	printf("RES: %.32Lf\n", res);
	printf("math: %.32Lf\n", cosl(x));
	return 0;
};


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
