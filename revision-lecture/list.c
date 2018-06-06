#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define TRUE 1
#define FALSE 0

struct node *create_list(int initial_values[], int length) {
  if (initial_values == NULL) {
    return NULL;
  }
  if (length <= 0) {
    return NULL;
  }
  // we are now guaranteed that the intial values array is not NULL and
  // thus dereference-able, and that the length provided is a positive
  // integer
  struct node *new_list_head = create_node(initial_values[0]);
  int input_array_index = 1;
  struct node *curr = new_list_head;
  while (input_array_index < length) {
    curr->next = create_node(initial_values[input_array_index]);
    curr = curr->next;
    input_array_index += 1;
  }
  return new_list_head;
}

struct node *create_node(int value) {
  struct node *new_node = malloc(sizeof(struct node) * 1);
  if (new_node == NULL) {
    fprintf(stderr, "error: node allocation failed.\n");
  }
  new_node->next = NULL;
  new_node->data = value;
  return new_node;
}

void print_list_recursively(struct node *list_head) {
  if (list_head != NULL) {
    printf("%d", list_head->data);
    if (list_head->next != NULL) {
      printf(",");
    }
    printf(" ");
    print_list_recursively(list_head->next);
  } else {
    printf("(end)");
  }
}

void print_list(struct node *list_head) {
  printf("[");
  print_list_recursively(list_head);
  printf("]\n");
}

void free_list(struct node *list_head) {
  if (list_head != NULL) {
    free_list(list_head->next);
    free(list_head);
  }
}

int is_odd(int value) {
  return value % 2;
}

int is_positive_integer(int value) {
  return value > 0;
}

int is_negative_integer(int value) {
  return value < 0;
}

int is_positive_or_negative_integer(int value) {
  return is_positive_integer(value) || is_negative_integer(value);
}

struct node *get_all_even_values(struct node *list) {
  if (list == NULL) {
    return NULL;
  }
  struct node *curr = list;
  struct node *even_list_head = NULL;
  while (curr != NULL) {
    if (is_odd(curr->data) == FALSE && is_positive_or_negative_integer(curr->data) == TRUE) {
      even_list_head = create_node(curr->data);
      break;
    }
    curr = curr->next;
  }
  struct node *even_list_curr = even_list_head;

  if (curr == NULL) {
    return even_list_head;
  }

  while (curr->next != NULL) {
    if (is_odd(curr->next->data) == FALSE && is_positive_or_negative_integer(curr->next->data) == TRUE) {
      even_list_curr->next = create_node(curr->next->data); 
      even_list_curr = even_list_curr->next;
    }
    curr = curr->next;
  }

  return even_list_head;
}

struct node *get_all_odd_values(struct node *list) {
  if (list == NULL) {
    return NULL;
  }
  struct node *curr = list;
  struct node *odd_list_head = NULL;
  // find the first odd element
  while (curr != NULL) {
    if (is_odd(curr->data) == TRUE && is_positive_or_negative_integer(curr->data) == TRUE) {
      odd_list_head = create_node(curr->data);
      // exit out of the loop when the first item in the odd list is
      // found
      break;
    }
    curr = curr->next;
  }
  // assign the current odd list pointer to the head of the newly
  // constructed list containing the odd elements of the input list
  struct node *odd_list_curr = odd_list_head;

  if (curr == NULL) {
    // no items left in the list after the first item
    return odd_list_head;
  } else if (curr->next == NULL) {
    // if the list is two items long, check if the second item is a
    // candidate
    if (is_odd(curr->data) == TRUE && is_positive_or_negative_integer(curr->data) == TRUE) {
      // if the second item in the list is also odd, 
      if (odd_list_head == NULL) {
        odd_list_head = create_node(curr->data);
      } else {
        odd_list_head->next = create_node(curr->data);
      }
      return odd_list_head;
    }
  }

  while (curr->next != NULL) {
    if (is_odd(curr->next->data) == TRUE && is_positive_or_negative_integer(curr->next->data) == TRUE) {
      odd_list_curr->next = create_node(curr->next->data); 
      odd_list_curr = odd_list_curr->next;
    }
    curr = curr->next;
  }

  return odd_list_head;
}

int count_common_elements(struct node *list_one, struct node *list_two) {
  if (list_one == NULL || list_two == NULL) {
    return 0;
  }
  // guaranteed that neither list is NULL and thus both input variables
  // may safely be dereferenced
  if (list_one->data == list_two->data) {
    // move to the next item in both lists
    return 1 + count_common_elements(list_one, list_two->next);
  } else if (list_one->data < list_two->data) {
    // move to the next item in the list with the lower current value
    // only
    return count_common_elements(list_one->next, list_two);
  } else {
    // move to the next item in the list with the lower current value
    // only
    return count_common_elements(list_one, list_two->next);
  }
}
