#include <stdio.h>
#include <stdlib.h>

struct node {
  unsigned int value;
  struct node *next;
};

struct node *create_list(unsigned int size);
struct node *create_node(unsigned int value);
void print_list(struct node *head);
void free_list(struct node *head);
void free_list_different_method(struct node *head);

int main (void) {
  struct node *list_one = create_list(100);
  print_list(list_one);
  free_list(list_one);
  // free_list_different_method(list_one);
  return 0;
}

struct node *create_list(unsigned int size) {
  if (size == 0) {
    return NULL;
  }
  unsigned int current_value = 1;
  struct node *head = create_node(current_value);
  current_value += 1;
  struct node *prev = NULL;
  struct node *curr = head;
  while (current_value <= size) {
    prev = curr;
    curr = create_node(current_value);
    prev->next = curr;
    current_value += 1;
  }
  return head;
}

void print_list(struct node *head) {
  printf("list start:");
  if (head == NULL) {
    printf(" [empty]\n");
    return;
  }
  struct node *current = head;
  while (current != NULL) {
    printf(" %d", current->value);
    current = current->next;
  }
  printf("\n");
}

void free_list(struct node *head) {
  // using a  r e c u r s i v e  method
  /*
  if (head != NULL) {
    free_list(head->next);
    free(head);
  }
  */
  free_list(head->next);
  free(head);
}

void free_list_different_method(struct node *head) {
  // using an iterative method
  struct node *current = NULL;
  struct node *next = head;
  while (next != NULL) {
    current = next;
    next = next->next;
    free(current);
  }
}

struct node *create_node(unsigned int value) {
  struct node *new_node = malloc(sizeof(struct node) * 1);
  if (new_node == NULL) {
    printf("error: cannot allocate memory for node %d\n", value);
    return NULL;
  }
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}
