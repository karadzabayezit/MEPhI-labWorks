#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/str_fns.h"

#define SUFFIX "_SUFFIX"

int is_first_vowel(const char *word) {
  char vowels[] = "AEIOUaeiouАИЕЁОУЫЭЮЯаиеёоуыэюя";
  return str_chr(vowels, word[0]) != NULL;
}

void add_suffix(char *res, char *word) {
  str_cpy(res, word);
  if(is_first_vowel(word)) {
    str_cat(res, SUFFIX);
  }
}

void process_str(const char *input, char *output) {
  char temp[1024] = {0};
  char word[1024] = {0};
  int output_len = 0;

  const char *curr = input;

  while (1) {

    printf("\n%c\n", *curr);
    while(is_space(*curr)) curr++;
    printf("\n%c\n", *curr);
    if(*curr == '\0') break;

    sscanf(curr, "%1023s", word);

    char new_word[1024];
    add_suffix(new_word, word);

    if (output_len > 0) {
      str_cat(temp, " ");
    }
    str_cat(temp, new_word);
    output_len++;

    curr += str_len(word);
  }

  str_cpy(output, temp);
}
