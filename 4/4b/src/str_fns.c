#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* str_cat (char des[], const char src[]) {
  int i = 0, j = 0;

  while (des[i] != '\0') i++;
  while (src[j] != '\0') {
    des[i + j] = src[j];
    j += 1;
  }
  des[i + j] = '\0';
  return des;
}

char* str_chr(const char* str, char c) {
    while (*str != '\0' && *str != c) str++;

    if (*str == c) {
        return (char*)str;
    }

    return NULL;
}

char* str_cpy(char *str_old, char *str_cp) {
  int i = 0;
  while ((str_old[i] = str_cp[i]) != '\0' ) i++;
  return str_old;
}

int str_len(char *str) {
  int i = 0;

  while (str[i] != '\0') i++;

  return i;
}

int is_space(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == '\v' || ch == '\f';
}



bool is_delim(char c, char *delim) {
  while(*delim != '\0')
  {
    if(c == *delim || is_space(c))
      return true;
    delim++;
  }
  return false;
}

char *str_tok(char *s, char *delim) {
  static char *p;
  if(!s) {
    s = p;
  }
  if(!s) {
    return NULL;
  }

  while(1) {
    if(is_delim(*s, delim)) {
      s++;
      continue;
    }
    if(*s == '\0') {
      return NULL;
    }
    break;
  }

  char *ret = s;
  while(1) {
    if(*s == '\0') {
      p = s;
      return ret;
    }
    if(is_delim(*s, delim)) {
      *s = '\0';
      p = s + 1;
      return ret;
    }
    s++;
  }
}

char* str_dup(char* str) {
	if(str == NULL) {
		return NULL;
	}

	size_t len = str_len(str) + 1;
	char* new_string = (char *)malloc(len * sizeof(char));

	if (new_string == NULL) {
		return NULL;
	}
	for (int i = 0; i < len; i++) {
	  new_string[i] = str[i];
	}
	return new_string;
}
