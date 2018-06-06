// implements functions in list.h
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

// ======= W13 Tut Problems ========
// returns a copy of the linked list
struct node *copy(struct node *head) {
  if (head == NULL) {
    return NULL;
  }
  int length = num_items(head);
  int *values_to_copy = malloc(sizeof(int) * length);
  if (values_to_copy == NULL) {
    return NULL;
  }
  int linked_list_index = 0;
  struct node *curr = head;
  while (linked_list_index < length) {
    values_to_copy[linked_list_index] = curr->data;
    curr = curr->next;
    linked_list_index += 1;
  }
  struct node *new_head = create_list(values_to_copy, length);
  return new_head;
}

// returns 1 if the two lists are identical, otherwise returns 0
int identical(struct node *head1, struct node *head2) {
  if (head1 == NULL && head2 == NULL) {
    return 1;
  } else if (head1 == NULL) {
    return 0;
  } else if (head2 == NULL) {
    return 0;
  } else {
    if (head1->data == head2->data) {
      return identical(head1->next, head2->next);
    } else {
      return 0;
    }
  }
}

int ordered_recursive(struct node *current, struct node *next) {
  if (next == NULL) {
    return 1; 
  } else {
    if (current->data < next->data) {
      return ordered_recursive(current->next, next->next);
    } else {
      return 0;
    }
  }
}

// returns 1 if list is in strictly increasing order, otherwise returns 0
int ordered(struct node *head) {
  if (head == NULL) {
    return 1;
  } else {
    return ordered_recursive(head, head->next);
  }
}

// given two lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements in both set1 and set2
struct node *set_intersection(struct node *set1, struct node *set2) {
  if (set1 == NULL || set2 == NULL) {
    // intersection is an empty list
    return NULL;
  }
  struct node *curr1 = set1;
  struct node *curr2 = set2;
  struct node *intersection_head = NULL;
  if (curr1->data < curr2->data) {
    // current values are not equal
    curr1 = curr1->next;
  } else if (curr1->data > curr2->data) {
    curr2 = curr2->next;
  } else {
    intersection_head = create_node(curr1->data);
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  if (curr1 == NULL || curr2 == NULL) {
    return NULL;
  } else if (intersection_head == NULL) {
    intersection_head = set_intersection(curr1, curr2);
  } else {
    intersection_head->next = set_intersection(curr1, curr2);
  }
  return intersection_head;    // replace this
}

// given two linked lists in strictly increasing order,
// return a new linked list (in strictly increasing order) of the elements in either set1 or set2
// no duplicates (only include them once)
struct node *set_union(struct node *set1, struct node *set2) {
  return NULL;    // replace this
}

// =================================

// given an array of integer values for data items
// returns the head of a linked list with these values
// in the order as they appear in the array
// size gives the size of the array
struct node *create_list(int values[], int size) {
  int i = 0;

  if (size <= 0) {
    // empty linked list (or invalid size)
    return NULL;
  }

  struct node *head = NULL;   // head of the linked list
  struct node *tmp = NULL;    // temporary item we're working with
  struct node *curr = NULL;   // current node we're looking at in the linked list

  while (i < size) {
    tmp = create_node(values[i]);

    // link this node onto our list
    if (head == NULL) {
      // this is the first node in the list
      head = tmp;
      curr = head;
    } else {
      // this is not the first node in the list
      // add it to the end, i.e. after curr
      curr->next = tmp;

      // reset curr to point at the new last node
      curr = tmp;
    }
    i++;
  }

  return head;
}

// creates a struct node with the given data value
// returns a pointer to this node
struct node *create_node(int dat) {
  struct node *new = malloc(sizeof(struct node));
  assert(new != NULL);
  new->data = dat;
  new->next = NULL;

  return new;
}

// prints out the list given the head of a list
void print_list(struct node *head) {
  struct node *curr;
  curr = head;

  while (curr != NULL) {
    printf("[ %d ]-->", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");

}

// frees all the elements in a linked list
void free_list(struct node *head) {
  if (head == NULL) {
    return;
  }
  free_list(head->next);
  free(head);
}

// return the number of items in the linked list
int num_items(struct node *head) {
  struct node *curr = head;
  int count = 0;

  while (curr != NULL) {
    count++;
    curr = curr->next;
  }

  return count;
}


