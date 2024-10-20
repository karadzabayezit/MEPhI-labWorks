#include <stdio.h>
#include <stdlib.h>

int inputX(long double *x);
int inputLimit(int *limit);

int main() {
	long double x;
	if(inputX(&x) == EOF) {
		return 0;
	};
	int limit;
	if(inputLimit(&limit) == EOF){
		return 0;
	};

	long double numInDegree = 1;
	long double factorial = 1;
	long double res;

	for(int i = 0; i < limit ; i++) {
		int degree = (i % 2 == 0) ? 1 : -1;
		printf("%d", degree);

		if(i > 0) {
			numInDegree *= x * x;
			factorial *= (2*i) * (2*i -1);
		};

		printf("degree: %Lf\n", numInDegree);
		printf("fac: %Lf\n", factorial);
		printf("\n");

		long double devided = numInDegree / factorial;

		res += (long double) degree * devided;
	}


	printf("RES: %.32Lf\n", res);

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
