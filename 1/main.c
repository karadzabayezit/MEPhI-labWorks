#include <stdio.h>

int getSum(int num) {
  int res = 0;

  while(num) {
    int currNum = num % 10;
    num /= 10;
    res += currNum;
  }

  return res;
};

int main(){
  int inputNum = 0;

  printf("Enter the number: ");
  scanf("%d", &inputNum);

  printf("The result is: ");
  printf("%d\n", getSum(inputNum));

  return 0;
};
