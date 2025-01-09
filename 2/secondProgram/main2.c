#include "./functions.h"

int main() {
	long double x;
	long double accurancy;
	int termsCount;
	if((input(&x) == EOF) || (input(&accurancy) == EOF)) {
		return 0;
	};
	long double res = getCosWhile(x, accurancy, &termsCount);
	printf("\nRESULT: %.32Lf\n", res);
	printf("TERMS COUNT: %d\n", termsCount);

	return 0;
};



