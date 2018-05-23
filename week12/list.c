#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node *create_node(int value) {
  struct node *new_node = malloc (sizeof(struct node) * 1);
  if (new_node == NULL) {
    fprintf(stderr, "error: new node allocation failed\n");
    return NULL;
  }
  new_node->next = NULL;
  new_node->data = value;
  return new_node;
}

struct node *create_list(int initial_value) {
  struct node *new_list = create_node(initial_value);
  return new_list;
}

void print_list(struct node *head_of_list) {
  if (head_of_list == NULL) {
    fprintf(stdout, " (end)\n");
  } else {
    // list is not empty
    // output the contents of this node to stdout and recurse
    fprintf(stdout, " %d", head_of_list->data);
    print_list(head_of_list->next);
  }
}

void free_list(struct node *head_of_list) {
  if (head_of_list != NULL) {
    free_list(head_of_list->next);
    free(head_of_list);
  }
}

struct node *sorted_insert(struct node *list, int value) {
  struct node *new_node = create_node(value);
  if (list == NULL) {
    // if the list is empty, create a new node and return it as the list
    return new_node;
  }
  struct node *curr = list;
  // check if the value should be inserted before the head of the list
  if (value < curr->data) {
    new_node->next = curr;
    return new_node;
  }
  // guaranteed that the value of the node to be inserted is greater
  // than the value of the head of the list
  while (curr->next != NULL) {
    if (curr->next->data > value && curr->data <= value) {
      // new value must be inserted here
      new_node->next = curr->next;
      curr->next = new_node;
      return list;
    }
    curr = curr->next;
  }
  // if new value is greater than any value stored in the list, 
  // append it to the end of the list
  // curr is guaranteed to be the last item in the list at this point
  curr->next = new_node;
  return list;
}

struct node *list_append(struct node *list1, struct node *list2) {
  // TODO: Implement!
  return NULL;
}

struct node *strings_to_list(int len, char *strings[]) {
  // TODO: Implement!
  return NULL;
}

struct node *merge_sorted(struct node *list1, struct node *list2) {
  // TODO: Implement!
  return NULL;
}
