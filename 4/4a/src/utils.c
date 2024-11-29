#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define SUFFIX "OKAY"

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

void process_str(const char *input, char *output) {
  char temp[1024] = {0};
  char word[1024] = {0};
  int output_len = 0;

  const char *curr = input;

  while (1) {

    while(isspace(*curr)) curr++;
    if(*curr == '\0') break;

    sscanf(curr, "%1023s", word);

    char new_word[1024];
    add_suffix(new_word, word);

    if (output_len > 0) {
      strcat(temp, " ");
    }
    strcat(temp, new_word);
    output_len++;

    curr += strlen(word);
  }

  strcpy(output, temp);
}
