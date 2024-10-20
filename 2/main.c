#include <stdio.h>
#include <stdlib.h>

long double inputX();
int inputLimit();

int main() {
	long double x = inputX();
	int limit = inputLimit();
	
	long double numInDegree = 1;
	long double factorial = 1;
	long double res;
		
	for(int i = 0; i <= limit ; i++) {
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
	}
	

	printf("RES: %.32Lf\n", res);

	return 0;
};


long double inputX() {
	long double x;
	char inputValue[20];

	
	while (1) {	
		printf("Gimme x: ");
		if(fgets(inputValue, sizeof(inputValue), stdin) == NULL){
			printf("\n!!!!!!!    EOF    !!!!!!!!!!!!!!\n");
			exit(0);
		};

		char *notNum;

		x = strtold(inputValue, &notNum);

		if(notNum == inputValue || *notNum != '\n') {
			printf("Incorrect. ");
		} else {
			return x;
		}		
	}
}

int inputLimit() {
	int limit;
	char inputValue[20];
	
	while (1) {	
		printf("Gimme limit: ");
		if(fgets(inputValue, sizeof(inputValue), stdin) == NULL){
			printf("\n!!!!!!!    EOF    !!!!!!!!!!!!!!\n");
			exit(0);
		};

		char *notNum;

		limit = strtol(inputValue, &notNum, 10);

		if(notNum == inputValue || *notNum != '\n') {
			printf("Incorrect. ");
		} else {
			return limit;
		}		
	}
}
