#include <stdio.h>
#include <stdlib.h>

long double input();


int main() {
	long double x; 
	if(input(&x) == EOF) {
		return 0;
	};
	long double accurancy;
	if(input(&accurancy)) {
		return 0;
	};
	
	long double numInDegree = 1;
	long double factorial = 1;
	long double res = 0;
	int i = 0;
	long double raz = 1;
	
	while ((raz < 0 ? raz * -1 : raz) > accurancy) {
		raz = res;
		int degree = -1;
		if(i % 2 == 0){
			degree = 1;
		};

		if(i > 0) {
			numInDegree *= x * x;
			factorial *= (2*i) * (2*i -1);
		};

		printf("degree: %Lf\n", numInDegree);
		printf("fac: %Lf\n", factorial);
		printf("\n");

		long double devided = numInDegree / factorial;	
		
		res += (long double) degree * devided;
		raz = (long double) raz - res;
		printf("%Lf", raz);
		i += 1; 
	}
	

	printf("RES: %.32Lf\n", res);

	return 0;
};


long double input(long double *x) {
	char inputValue[30];
	long double var;
	
	while (1) {	
		printf("Gimme value: ");
		if(fgets(inputValue, sizeof(inputValue), stdin) == NULL){
			printf("\n!!!!!!!    EOF    !!!!!!!!!!!!!!\n");
			return EOF;
		};

		char *notNum;

		var = strtold(inputValue, &notNum);

		if(notNum == inputValue || *notNum != '\n') {
			printf("Incorrect. ");
		} else {
			return 0;
		}		
	}
	*x = var;
	printf("%Lf", *x);
}

