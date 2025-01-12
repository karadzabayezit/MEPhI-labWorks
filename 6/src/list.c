#include <stdio.h>
#include <stdlib.h>

#include "../include/list.h"

void free_list(Node *head) {
  while (head) {
    Node *temp = head;
    head = head->next;
    free(temp);
  }
}

void print_list(const Node *head) {
  putchar('"');
  while (head) {
    putchar(head->data);
    head = head->next;
  }
  putchar('"');
}