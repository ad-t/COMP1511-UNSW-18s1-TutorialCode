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
  return 0;
}

struct node *create_list(unsigned int size) {
  if (size == 0) {
    return NULL;
  }
  unsigned int node_value = 1;
  struct node *head = create_node(node_value);
  node_value += 1;
  struct node *current = head;
  struct node *previous = head;
  while (node_value <= size) {
    current = create_node(node_value);
    previous->next = current;
    previous = current;
    node_value += 1;
  }
  return head;
}

void print_list(struct node *head) {
  struct node *current = head;
  printf("list start:");
  while (current != NULL) {
    printf(" %u", current->value);
    current = current->next;
  }
  printf("\n");
}

void free_list(struct node *head) {
  if (head != NULL) {
    free_list(head->next);
    free(head);
  }
}

void free_list_different_method(struct node *head) {
  struct node *current = head;
  struct node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}

struct node *create_node(unsigned int value) {
  struct node *new_node = malloc(sizeof(struct node) * 1);
  if (new_node  == NULL) {
    printf("error: malloc failed for create list\n");
    return NULL;
  }
  new_node->value = value;
  return new_node;
}
