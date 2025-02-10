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
  if (!head || !(*head)) return 0;

  Node *firstDot = NULL;
  Node *last_semicolon = NULL;

  while (*head && ((*head)->data == ' ' || (*head)->data == '\t')) {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
  }

  Node *curr = *head;
  while (curr) {
    if (!firstDot && curr->data == '.') {
      firstDot = curr;
    }
    if (curr->data == ';') {
      last_semicolon = curr;
    }
    curr = curr->next;
  }

  if (firstDot) {
    Node *temp = *head;
    while (temp != firstDot) {
			if(temp == last_semicolon) last_semicolon = NULL;
      Node *prev = temp;
      temp = temp->next;
      free(prev);
    }
    *head = firstDot;
  }

  if (last_semicolon) {
    Node *temp = last_semicolon->next;
    last_semicolon->next = NULL;
    while (temp) {
      Node *prev = temp;
      temp = temp->next;
      free(prev);
      }
  }

  Node *prev = NULL;
  curr = *head;
  int last_was_space = 0;

  while (curr) {
    if (curr->data == ' ' || curr->data == '\t') {
      if (last_was_space || !prev) {
      	Node *temp = curr;
        prev->next = curr->next;
        curr = curr->next;
        free(temp);
        continue;
      }
      curr->data = ' ';
      last_was_space = 1;
    } else {
      last_was_space = 0;
    }
    prev = curr;
    curr = curr->next;
  }

  curr = *head;
  prev = NULL;
  while (curr && curr->next) {
    prev = curr;
    curr = curr->next;
  }

  if (curr && (curr->data == ' ' || curr->data == '\t')) {
    if (prev) prev->next = NULL;
    free(curr);
  }

  return 0;
}

