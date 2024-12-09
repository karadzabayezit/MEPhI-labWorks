#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/str_fns.h"

#define SUFFIX "_SUFFIX"

int is_first_vowel(const char *word) {
  char vowels[] = "AEIOUaeiou";
  return str_chr(vowels, word[0]) != NULL;
}

void process_str(const char *input, char **output) {
  if(input == NULL) {
  	printf("Empty stringi ;)\n");
  	return;
  }
  char *delimeters = " ,.";

  char* tmp_input = str_dup(input);
  char* tmp_word = str_tok(tmp_input, delimeters);
  if(tmp_word == NULL) {
  	*output = tmp_input;
  	return;
  }

  int vowels_count = 0;
  while(tmp_word != NULL) {
    if(is_first_vowel(tmp_word)) {
      vowels_count++;
    }
    tmp_word = str_tok(NULL, delimeters);
  }
  char *input_copy = str_dup(input);
  size_t output_len = str_len(input_copy) + (vowels_count * str_len(SUFFIX)) + 1;
  char *temp = calloc(output_len, sizeof(char));
  if(temp == NULL) {
  	printf("Mem alloc err!");
  	return;
  }
  
  char *word = str_tok(input_copy, delimeters);

  while (word != NULL) {
    str_cat(temp, word);
    if(is_first_vowel(word)) {
      str_cat(temp, SUFFIX);
    }

    word = str_tok(NULL, delimeters);

    if(word != NULL) {
      str_cat(temp, " ");
    }
  }
  
  free(tmp_input);
  free(input_copy);
  *output = temp;
}
