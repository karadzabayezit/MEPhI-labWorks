#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SUFFIX "_SUFFIX"

int is_first_vowel(const char *word) {
  char vowels[] = "AEIOUaeiou";
  return strchr(vowels, word[0]) != NULL;
}

void add_suffix(char *res, const char *word) {
  strcpy(res, word);
  if(is_first_vowel(word)) {
    strcat(res, SUFFIX);
  }
}

void process_str(const char *input, char **output) {
  char *delimeters = " ,.";

  char* tmp_input = strdup(input);
  char* tmp_word = strtok(tmp_input, delimeters);
  int vowels_count = 0;
  while(tmp_word != NULL) {
    if(is_first_vowel(tmp_word)) {
      vowels_count++;
    }
    tmp_word = strtok(NULL, delimeters);
  }
  printf("%d\n", vowels_count);
  size_t output_len = strlen(input);
  char *temp;
  output_len += (vowels_count * strlen(SUFFIX));
  temp = malloc(output_len * sizeof(char));

  char *input_copy = strdup(input);
  char *word = strtok((char*)input_copy, delimeters);

  while (word != NULL) {
    size_t temp_len = sizeof(temp);

    if(is_first_vowel(word)) {
      strcat(temp, word);
      strcat(temp, SUFFIX);
    } else {
      strcat(temp, word);
    }

    printf("%s\n", temp);
    output_len += strlen(word) + strlen(SUFFIX);
    word = strtok(NULL, delimeters);


    if(word && strlen(word) > 0) {
      strcat(temp, " ");
    }
  }

  *output = temp;
}
