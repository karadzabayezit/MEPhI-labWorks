#include <stdio.h>

#include "../include/list.h"
#include "../include/utils.h"

int main() {
  Node *head = NULL;
  char c;

  printf("Enter strings (Ctrl+D to end):\n");

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      printf("Original: ");
      print_list(head);
      printf("\n");
      modify_list(&head);
      printf("Modified: ");
      print_list(head);
      printf("\n\n");
      free_list(head);
      head = NULL;
    	printf("Enter strings (Ctrl+D to end):\n");

    } else {
      append(&head, c);
    }
  }

  return 0;
}
