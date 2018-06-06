#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

// testing groups
void test_list_creation();
void test_get_all_even_values_function();
void test_get_all_odd_values_function();

int main (int argc, char * argv[]) {

  int test_array_one[] = { 1, 2, 3, 4, 5, 6, 7 };
  int test_array_two[] = { 2, 4, 6, 8 };
  struct node *test_list_one = create_list(test_array_one, 7);
  struct node *test_list_two = create_list(test_array_two, 4);
  print_list(test_list_one);
  print_list(test_list_two);
  assert(count_common_elements(test_list_one, test_list_two) == 3);
  /*
  free_list(test_list_one);
  free_list(test_list_two);
  */

  int test_array_three[] = { -5, -3, 1, 2, 3, 4, 5, 6, 8 };
  int test_array_four[] = { -5, 2, 4, 6, 8 };
  struct node *test_list_three = create_list(test_array_three, 9);
  struct node *test_list_four = create_list(test_array_four, 5);
  print_list(test_list_three);
  print_list(test_list_four);
  assert(count_common_elements(test_list_three, test_list_four) == 5);
  /*
  free_list(test_list_three);
  free_list(test_list_four);
  */
  
  test_list_creation();
  test_get_all_even_values_function();
  test_get_all_odd_values_function();
  /*
  */

  return EXIT_SUCCESS;
}

void test_list_creation() {
  printf("Testing list creation...\n");
  printf("\tNULL array input...");
  struct node *null_list = create_list(NULL, 0);
  assert(null_list == NULL);
  printf("OK\n");

  printf("\tNon-NULL array with zero length...");
  int single_item_array[] = { 1 };
  null_list = create_list(single_item_array, 0);
  assert(null_list == NULL);
  printf("OK\n");

  printf("\tNon-NULL array with length as a negative integer...");
  null_list = create_list(single_item_array, -42);
  assert(null_list == NULL);
  printf("OK\n");

  printf("\tSingle item array...");
  struct node *single_element_list = create_list(single_item_array, 1);
  assert(single_element_list != NULL);
  assert(single_element_list->data == 1);
  assert(single_element_list->next == NULL);
  free_list(single_element_list);
  printf("OK\n");

  printf("\tInput array with two items...");
  int two_item_array[] = { 1, 42 };
  struct node *two_item_list = create_list(two_item_array, 2);
  assert(two_item_list != NULL);
  assert(two_item_list->data == 1);
  assert(two_item_list->next != NULL);
  assert(two_item_list->next->data == 42);
  assert(two_item_list->next->next == NULL);
  free_list(two_item_list);
  printf("OK\n");

  printf("\tInput array with five items...");
  int five_item_array[] = { 1, 42, 17, 81, -5 };
  struct node *five_item_list = create_list(five_item_array, 5);
  assert(five_item_list != NULL);
  assert(five_item_list->data == 1);
  assert(five_item_list->next != NULL);
  assert(five_item_list->next->data == 42);
  assert(five_item_list->next->next != NULL);
  assert(five_item_list->next->next->data == 17);
  assert(five_item_list->next->next->next != NULL);
  assert(five_item_list->next->next->next->data == 81);
  assert(five_item_list->next->next->next->next != NULL);
  assert(five_item_list->next->next->next->next->data == -5);
  assert(five_item_list->next->next->next->next->next == NULL);
  free_list(five_item_list);
  printf("OK\n");
}

void test_get_all_even_values_function() {
  printf("Testing get_all_even_values function...\n");
  struct node *test_input_list = NULL;
  struct node *test_output = NULL;
  int single_odd_array[] = { 7 };
  int single_even_array[] = { 8 };
  int three_even_array[] = { 2, 4, -6 };
  int two_odd_values[] = { 7, 13 };
  int two_odd_two_even_array[] = { 7, 8, 13, 14 };
  int two_odd_followed_by_even_array[] = { 7, 13, 8 };
  int one_even_followed_by_two_odd_array[] = { 8, 7, 13 };
  int one_even_between_two_odd_array[] = { 7, 8, 13 };
  int one_odd_between_two_even_array[] = { 6, 7, 14 };

  printf("\tNULL input...");
  test_output = get_all_even_values(NULL);
  assert(test_output == NULL);
  printf("OK\n");

  printf("\tSingle odd value in input...");
  test_input_list = create_list(single_odd_array, 1);
  test_output = get_all_even_values(test_input_list);
  assert(test_output == NULL);
  printf("OK\n");

  printf("\tSingle even value in input...");
  test_input_list = create_list(single_even_array, 1);
  test_output = get_all_even_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 8);
  assert(test_output->next == NULL);
  printf("OK\n");

  printf("\tThree even values in input...");
  test_input_list = create_list(three_even_array, 3);
  test_output = get_all_even_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 2);
  assert(test_output->next != NULL);
  assert(test_output->next->data == 4);
  assert(test_output->next->next != NULL);
  assert(test_output->next->next->data == -6);
  assert(test_output->next->next->next == NULL);
  printf("OK\n");

  printf("\tTwo odd values in input...");
  test_input_list = create_list(two_odd_values, 2);
  test_output = get_all_even_values(test_input_list);
  assert(test_output == NULL);
  printf("OK\n");

  printf("\tTwo odd and two even values in input...");
  test_input_list = create_list(two_odd_two_even_array, 4);
  test_output = get_all_even_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 8);
  assert(test_output->next != NULL);
  assert(test_output->next->data == 14);
  assert(test_output->next->next == NULL);
  printf("OK\n");

  printf("\tTwo odd values and an even value at the end in input...");
  test_input_list = create_list(two_odd_followed_by_even_array, 3);
  test_output = get_all_even_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 8);
  assert(test_output->next == NULL);
  printf("OK\n");

  printf("\tOne even value followed by two odd values in input...");
  test_input_list = create_list(one_even_followed_by_two_odd_array, 3);
  test_output = get_all_even_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 8);
  assert(test_output->next == NULL);
  printf("OK\n");

  printf("\tOne even value followed between two odd values in input...");
  test_input_list = create_list(one_even_between_two_odd_array, 3);
  test_output = get_all_even_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 8);
  assert(test_output->next == NULL);
  printf("OK\n");

  printf("\tOne odd value followed between two even values in input...");
  test_input_list = create_list(one_odd_between_two_even_array, 3);
  test_output = get_all_even_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 6);
  assert(test_output->next != NULL);
  assert(test_output->next->data == 14);
  assert(test_output->next->next == NULL);
  printf("OK\n");
}

void test_get_all_odd_values_function() {
  printf("Testing get_all_odd_values function...\n");
  struct node *test_input_list = NULL;
  struct node *test_output = NULL;
  int single_odd_array[] = { 7 };
  int single_even_array[] = { 8 };
  int three_even_array[] = { 2, 4, -6 };
  int two_odd_values[] = { 7, 13 };
  int two_odd_two_even_array[] = { 7, 8, 13, 14 };
  int two_odd_followed_by_even_array[] = { 7, 13, 8 };
  int one_even_followed_by_two_odd_array[] = { 8, 7, 13 };
  int one_even_between_two_odd_array[] = { 7, 8, 13 };
  int one_odd_between_two_even_array[] = { 6, 7, 14 };

  printf("\tNULL input...");
  test_output = get_all_odd_values(NULL);
  assert(test_output == NULL);
  printf("OK\n");

  printf("\tSingle odd value in input...");
  test_input_list = create_list(single_odd_array, 1);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 7);
  assert(test_output->next == NULL);
  printf("OK\n");

  printf("\tSingle even value in input...");
  test_input_list = create_list(single_even_array, 1);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output == NULL);
  printf("OK\n");

  printf("\tThree even values in input...");
  test_input_list = create_list(three_even_array, 3);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output == NULL);
  printf("OK\n");

  printf("\tTwo odd values in input...");
  test_input_list = create_list(two_odd_values, 2);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 7);
  assert(test_output->next != NULL);
  assert(test_output->next->data == 13);
  assert(test_output->next->next == NULL);
  printf("OK\n");

  printf("\tTwo odd and two even values in input...");
  test_input_list = create_list(two_odd_two_even_array, 4);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 7);
  assert(test_output->next != NULL);
  assert(test_output->next->data == 13);
  assert(test_output->next->next == NULL);
  printf("OK\n");

  printf("\tTwo odd values and an even value at the end in input...");
  test_input_list = create_list(two_odd_followed_by_even_array, 3);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 7);
  assert(test_output->next != NULL);
  assert(test_output->next->data == 13);
  assert(test_output->next->next == NULL);
  printf("OK\n");

  printf("\tOne even value followed by two odd values in input...");
  test_input_list = create_list(one_even_followed_by_two_odd_array, 3);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 7);
  assert(test_output->next != NULL);
  assert(test_output->next->data == 13);
  assert(test_output->next->next == NULL);
  printf("OK\n");

  printf("\tOne even value followed between two odd values in input...");
  test_input_list = create_list(one_even_between_two_odd_array, 3);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 7);
  assert(test_output->next != NULL);
  assert(test_output->next->data == 13);
  assert(test_output->next->next == NULL);
  printf("OK\n");

  printf("\tOne odd value followed between two even values in input...");
  test_input_list = create_list(one_odd_between_two_even_array, 3);
  test_output = get_all_odd_values(test_input_list);
  assert(test_output != NULL);
  assert(test_output->data == 7);
  assert(test_output->next == NULL);
  printf("OK\n");
}
