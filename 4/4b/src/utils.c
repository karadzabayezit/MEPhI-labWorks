#include <readline/chardefs.h>
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
  char *input_copy = strdup(input);
  const char delimeters[] = " ,.";
  char *word = strtok((char*)input_copy, delimeters);
  size_t output_len = strlen(input_copy);
  char *temp;

  temp = malloc(2*output_len * sizeof(char));

  while (word != NULL) {
    size_t temp_len = sizeof(temp);

    if(is_first_vowel(word)) {
      strcat(temp, word);
      strcat(temp, SUFFIX);
      printf("VOWEL: %s\n", temp);
    } else {
      strcat(temp, word);
    }


    output_len += str_len(word) + strlen(SUFFIX);
    word = strtok(NULL, delimeters);

    if(2*output_len > temp_len) {
      temp = realloc(temp, temp_len*2);
    }
    if(word && strlen(word) > 0) {
      strcat(temp, " ");
    }
  }

  strcpy(output, temp);



  // char temp[1024] = {0};
  // char word[1024] = {0};
  // int output_len = 0;

  // const char *curr = input;

  // while (1) {

  //   while(is_space(*curr)) curr++;
  //   if(*curr == '\0') break;

  //   sscanf(curr, "%1023s", word);

  //   char new_word[1024];
  //   add_suffix(new_word, word);

  //   if (output_len > 0) {
  //     str_cat(temp, " ");
  //   }
  //   str_cat(temp, new_word);
  //   output_len+= str_len(word);

  //   curr += str_len(word);
  // }

  // str_cpy(output, temp);
}
