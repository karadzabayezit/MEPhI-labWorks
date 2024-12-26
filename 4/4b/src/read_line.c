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

    if (n == EOF) {
      free(res);
      return NULL;
    } else if (n > 0) {
        size_t chunk_len = strlen(buf);
        char *temp = realloc(res, len + chunk_len + 1);
        if (temp == NULL) {
            free(res);
            return NULL;
        }
        res = temp;
        memcpy(res + len, buf, chunk_len);
        len += chunk_len;
    } else {
        scanf("%*c");
    }
    if (n <= 0) {
        break;
    }
  } while (n > 0);

  if (len > 0) {
    res[len] = '\0';
  }
  else {
    free(res);
    res = calloc(1, sizeof(char));
  }

  return res;
}
