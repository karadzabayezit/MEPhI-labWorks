#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SUFFIX "_SUFFIX"

int is_first_vowel(const char *word) {
  char vowels[] = "AEIOUaeiou";
  return strchr(vowels, word[0]) != NULL;
}

void process_str(const char *input, char **output) {
  char *delimeters = " ,.";

  char* tmp_input = strdup(input);
  char* tmp_word = strtok(tmp_input, delimeters);
  if(tmp_word == NULL) {
    free(tmp_input);
    *output = strdup("");
    return;
  }

  int vowels_count = 0;
  while(tmp_word != NULL) {
    if(is_first_vowel(tmp_word)) {
      vowels_count++;
    }
    tmp_word = strtok(NULL, delimeters);
  }

  size_t output_len = strlen(input) + (vowels_count * strlen(SUFFIX)) + 1;
  char *temp = calloc(output_len, sizeof(char));

  if (temp == NULL) {
    perror("Memory allocation failed");
    free(temp);
    return;
  }

  char *input_copy = strdup(input);
  char *word = strtok(input_copy, delimeters);
  while (word != NULL) {
    strcat(temp, word);
    if(is_first_vowel(word)) {
      strcat(temp, SUFFIX);
    }

    word = strtok(NULL, delimeters);


    if(word != NULL) {
      strcat(temp, " ");
    }
  }
  free(tmp_input);
  free(input_copy);
  *output = temp;
}
