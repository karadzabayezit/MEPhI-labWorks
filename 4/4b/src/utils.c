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
  size_t output_len = str_len(tmp_input);
  char* tmp_word = str_tok(tmp_input, delimeters);
  int vowels_count = 0;
  while(tmp_word != NULL) {
    if(is_first_vowel(tmp_word)) {
      vowels_count++;
    }
    tmp_word = str_tok(NULL, delimeters);
  }
  free(tmp_input);
  char *temp;
  output_len += (vowels_count * str_len(SUFFIX));
  temp = malloc(output_len * sizeof(char));

  char *input_copy = str_dup(input);
  char *word = str_tok((char*)input_copy, delimeters);

  while (word != NULL) {
    size_t temp_len = sizeof(temp);

    if(is_first_vowel(word)) {
      str_cat(temp, word);
      str_cat(temp, SUFFIX);
    } else {
      str_cat(temp, word);
    }


    output_len += str_len(word) + str_len(SUFFIX);
    word = str_tok(NULL, delimeters);

    if(word && str_len(word) > 0) {
      str_cat(temp, " ");
    }
  }
  free(input_copy);
  *output = temp;
}
