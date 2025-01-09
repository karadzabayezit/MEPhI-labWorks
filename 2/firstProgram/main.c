#include "./functions.h"

int main() {
	long double x;
	int limit;
	if((inputX(&x) == EOF) || (inputLimit(&limit) == EOF)) {
		return 0;
	};
	long double res = getCos(x, limit);
	printf("RES: %.32Lf\n", res);
	printf("math: %.32Lf\n", cosl(x));
	return 0;
};
