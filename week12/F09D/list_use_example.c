#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// executable file takes in no arguments at runtime, therefore
// argv and argc are not implictly created
int main (int argc, char *argv[]) {

  struct node *l1 = create_list(5);
  struct node *l2 = create_list(1);
  struct node *appended_list = list_append(NULL, NULL);
  printf("appended list:");
  print_list(appended_list);
  free_list(appended_list);

  char *powers[] = {"2", "4", "8", "16"};
  struct node *head = strings_to_list(argc - 1, &argv[1]);
  printf("string array to linked list:");
  print_list(head);
  free_list(head);

  struct node *sorted1 = create_list(5);
  struct node *sorted2 = create_list(3);

  sorted1 = sorted_insert(sorted1, 4);
  sorted1 = sorted_insert(sorted1, 8);
  sorted1 = sorted_insert(sorted1, 2);
  sorted1 = sorted_insert(sorted1, 12);
  sorted1 = sorted_insert(sorted1, -1);
  printf("sorted1:");
  print_list(sorted1);

  sorted2 = sorted_insert(sorted2, 5);
  sorted2 = sorted_insert(sorted2, -15);
  sorted2 = sorted_insert(sorted2, 9);
  sorted2 = sorted_insert(sorted2, 3);
  sorted2 = sorted_insert(sorted2, 13);
  printf("sorted2:");
  print_list(sorted2);

  struct node *merged_list = merge_sorted(sorted1, sorted2);
  printf("merged:");
  print_list(merged_list);
  free_list(merged_list);

  return 0;
}
