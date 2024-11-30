#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* str_cat (char str[], char output[]) {
  int i = 0;
  int j = 0;
  char* pointer = str;
  while (str[i] != '\0') i++;
  while (output[j] != '\0') {
    str[i++] = output[j++];
  }
  return pointer;
}

char* str_chr(const char* str, int c) {
    while (*str != '\0' && *str != (char)c) {
        str++;
    }

    if (*str == (char)c) {
        return (char*)str;
    }

    return NULL;
}

char* str_cpy(char *str_old, char *str_cp) {
  int i = 0;
  char* pointer = str_old;
  while (str_old[i] != '\0' || str_cp[i] != '\0' ) {
    str_old[i] = str_cp[i];
    i++;
  }
  return pointer;
}

int str_len(char *str) {
  int i = 0;

  while (str[i] != '\0') i++;

  return i+1;
}

int is_space(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == '\v' || ch == '\f';
}
