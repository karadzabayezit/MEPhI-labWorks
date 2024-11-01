#include "./functions.h"

int main() {
	long double x;
	long double accurancy;

	if((input(&x) == EOF) || (input(&accurancy) == EOF)) {
		return 0;
	};

	long double res = getCosWhile(x, accurancy);

	printf("RES: %.32Lf\n", res);

	return 0;
};



