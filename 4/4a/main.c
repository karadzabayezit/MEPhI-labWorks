#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>
#include <readline/history.h>

#define SUFFIX "OKAY"

int starts_with_vowel(const char *word) {
    char vowels[] = "AEIOUaeiou";
    return word && strchr(vowels, word[0]) != NULL;
}

void append_suffix(char *dest, const char *word) {
    strcpy(dest, word);
    if (starts_with_vowel(word)) {
        strcat(dest, SUFFIX);
    }
}

void process_line(const char *input, char *output) {
    char temp[1024] = {0};
    char word[1024] = {0};
    size_t output_len = 0;

    const char *current = input;

    while (1) {

        while (isspace(*current)) current++;
        if (*current == '\0') break;


        sscanf(current, "%1023s", word);

        char processed_word[1024];
        append_suffix(processed_word, word);

        if (output_len > 0) {
            strcat(temp, " ");
            output_len++;
        }
        strcat(temp, processed_word);
        output_len += strlen(processed_word);

        current += strlen(word);
    }

    strcpy(output, temp);
}


int main() {
    char *input = NULL;
    char output[1024];

    printf("Введите строки (завершение ввода: Ctrl+D / Ctrl+Z):\n");
    while ((input = readline("")) != NULL) {

        process_line(input, output);

        printf("\"%s\" -> \"%s\"\n", input, output);

        free(input);
    }

    return 0;
}
