#include <readline/chardefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/str_fns.h"

#define SUFFIX "_SUFFIX"

int is_first_vowel(const char *word) {
  char vowels[] = "AEIOUaeiou";
  return str_chr(vowels, word[0]) != NULL;
}

void add_suffix(char *res, char *word) {
  str_cpy(res, word);
  if(is_first_vowel(word)) {
    str_cat(res, SUFFIX);
  }
}

void process_str(const char *input, char **output) {
  char *delimeters = " ,.";

  char* tmp_input = str_dup(input);
  char* tmp_word = str_tok(tmp_input, delimeters);
  int vowels_count = 0;
  while(tmp_word != NULL) {
    if(is_first_vowel(tmp_word)) {
      vowels_count++;
    }
    tmp_word = str_tok(NULL, delimeters);
  }
  printf("%d\n", vowels_count);
  size_t output_len = strlen(input);
  char *temp;
  output_len += (vowels_count * str_len(SUFFIX));
  temp = malloc(output_len * sizeof(char));

  char *input_copy = str_dup(input);
  char *word = str_tok((char*)input_copy, delimeters);

  while (word != NULL) {
    size_t temp_len = sizeof(temp);

    if(is_first_vowel(word)) {
      strcat(temp, word);
      strcat(temp, SUFFIX);
    } else {
      strcat(temp, word);
    }


    output_len += str_len(word) + strlen(SUFFIX);
    word = str_tok(NULL, delimeters);

    if(2*output_len > temp_len) {
      temp = realloc(temp, temp_len*2);
    }
    if(word && strlen(word) > 0) {
      strcat(temp, " ");
    }
  }

  *output = temp;
}
