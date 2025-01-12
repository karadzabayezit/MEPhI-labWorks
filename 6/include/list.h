#ifndef LIST
#define LIST

typedef struct Node {
  char data;
  struct Node *next;
} Node;

void free_list(Node *head);
void print_list(const Node *head);

#endif