#include "./functions.h"

long double getCosWhile(long double radians, long double accurancy) {
	long double numInDegree = 1;
	long double factorial = 1;
	long double res = 1;
	long double raz = 1;
	radians = fmod(radians, 2 * M_PI);

	int i = 1;
	do {
        numInDegree *= -1 * radians * radians;
        factorial *= (2 * i) * (2 * i - 1);

        raz = numInDegree / factorial;
        res += raz;
        i += 1;
    } while (fabsl(raz) > accurancy);

	return res;
}

int input(long double *x) {
  char inputValue[30];

  while (1) {
      printf("Gimme value: ");
      if (fgets(inputValue, sizeof(inputValue), stdin) == NULL) {
          printf("\n!!!!!!!    EOF    !!!!!!!!!!!!!!\n");
          return EOF;
      }

      char *notNum;
      long double var = strtold(inputValue, &notNum);

      if (notNum == inputValue || *notNum != '\n') {
          printf("Incorrect. ");
      } else {
          *x = var;
          return 0;
      }
  }
}