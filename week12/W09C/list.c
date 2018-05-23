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

struct node *list_append(struct node *list1, struct node *list2) {
  if (list1 == NULL && list2 == NULL) {
    return NULL;
  } else if (list1 == NULL) {
    return list2;
  } else if (list2 == NULL) {
    return list1;
  } else {
    struct node *current_node = list1;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    // current_node is guaranteed to contain the end of list1
    current_node->next = list2;
    return list1;
  }
}

struct node *strings_to_list(int len, char *strings[]) {
  if (len <= 0) {
    return NULL;
  }
  if (strings == NULL) {
    return NULL;
  }
  struct node *head = create_node(atoi(strings[0]));
  struct node *curr = head;
  unsigned int string_index = 1;
  while (string_index < len) {
    int new_value = atoi(strings[string_index]);
    struct node *new_node = create_node(new_value);
    curr->next = new_node;
    curr = curr->next;
    string_index += 1;
  }
  return head;
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
  //
  // curr is guaranteed to be the last item in the list at this point
  curr->next = new_node;
  return list;
}

struct node *merge_sorted(struct node *list1, struct node *list2) {
  if (list1 == NULL && list2 == NULL) {
    // both lists are empty, therefore the merged list must be empty
    return NULL;
  } else if (list1 == NULL) {
    // list 1 is empty, therefore the merged list would be list2
    return list2;
  } else if (list2 == NULL) {
    // list 2 is empty, therefore the merged list would be list1
    return list1;
  } else {
    // in the case where both lists are not empty, use the general 
    // solution
    struct node *first_list_curr = list1;
    struct node *second_list_curr = list2;
    struct node *merged_list_head = NULL;
    // compare the values of each current pointer for each list and 
    // decide which head of which list will be the head of the
    // merged list
    if (first_list_curr->data < second_list_curr->data) {
      merged_list_head = first_list_curr;
      first_list_curr = first_list_curr->next;
    } else {
      merged_list_head = second_list_curr;
      second_list_curr = second_list_curr->next;
    }
    struct node *merged_list_curr = merged_list_head;
    // merge all remaining values
    while (first_list_curr != NULL && second_list_curr != NULL) {
      if (first_list_curr->data < second_list_curr->data) {
        // if the first list current value is less than the second
        // list current value, add it to the merged list and iterate
        // the first list current pointer
        merged_list_curr->next = first_list_curr;
        first_list_curr = first_list_curr->next;
      } else {
        // otherwise, the second list current value is equal to or 
        // greater than the first list current value and the second list
        // current value is added to the merged list and the second list
        // current pointer is iterated
        merged_list_curr->next = second_list_curr;
        second_list_curr = second_list_curr->next;
      }
      // the merged list current pointer is moved forward
      merged_list_curr = merged_list_curr->next;
    }
    // if either list has reached its end, append the rest of the 
    // other list to the merged list
    if (first_list_curr == NULL) {
      merged_list_curr->next = second_list_curr;
    } else {
      merged_list_curr->next = first_list_curr;
    }
    // return the head of the merged list
    return merged_list_head;
  }
}
