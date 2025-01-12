#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/list.h"

int append(Node **head, char c) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (!new_node) {
    perror("Memory allocation failed");
    return -1;
  }

  new_node->data = c;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    Node *temp = *head;
    while (temp->next) {
      temp = temp->next;
    }
      temp->next = new_node;
  }

	return 0;
}

int modify_list(Node **head) {
  while (*head && (*head)->data != '.') {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
  }

  Node *last_semicolon = NULL;
  Node *curr = *head;
  while (curr) {
    if (curr->data == ';') {
      last_semicolon = curr;
    }
    curr = curr->next;
  }

  if (last_semicolon) {
    Node *temp = last_semicolon->next;
    last_semicolon->next = NULL;
    while (temp) {
      Node *next = temp->next;
      free(temp);
      temp = next;
    }
	}

	return 0;
}