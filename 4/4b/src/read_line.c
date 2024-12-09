#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/str_fns.h"

char* read_line(char *str) {
  char buf[81] = {0}; // BUFSIZ - константа для длины буфера
  char *res = NULL;
  int len = 0;
  int n = 0;

  printf("%s", str);
  do {
    n = scanf("%80[^\n]", buf);
    if (n < 0 && !res) {
        return NULL;
    }
    else if (n > 0) {
      int chunk_len = str_len(buf);
      int str_len = len + chunk_len;
      char* temp = realloc(res, str_len + 1);
      if(temp == NULL) {
        free(res);
	return NULL;
      }
      res = temp;
      memcpy(res + len, buf, chunk_len);
      len = str_len;
      }
    else {
      scanf("%*c");}
  } while (n > 0);

  if (len > 0) {
    res[len] = '\0';
  }
  else {
    res = calloc(1, sizeof(char));
  }
  if(len == 0 && n == 0) {
  	return NULL;
  }

  return res;
}
