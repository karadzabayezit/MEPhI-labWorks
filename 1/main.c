#include <stdio.h>
#include "./getSum/getSum.h"

int main(){
  int inputNum = 0;

  printf("Enter the number: ");
  scanf("%d", &inputNum);

  printf("The result is: ");
  printf("%d\n", getSum(inputNum));
  
  return 0;
};
