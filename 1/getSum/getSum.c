int getSum(int num) {
  int res = 0;

  while(num) {
    int currNum = num % 10;
    num /= 10;
    res += currNum;
  }

  return res;
};
