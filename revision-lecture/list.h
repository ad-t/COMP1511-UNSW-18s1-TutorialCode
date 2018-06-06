#ifndef LIST_H
#define LIST_H

// node definition
struct node {
  int data;
  struct node *next;
};

/*
 * Function to create a linked list given an array of initial values
 * and the length of the provided array.
 * 
 * Returns a non-NULL pointer to a heap allocated node struct and
 * returns a NULL pointer if list initialisation is unsuccessful.
 */

struct node *create_list(int initial_values[], int length);

/*
 * Function which, given an integer value, will create a node struct
 * with the `data' field being set to the provided parameter `value'.
 *
 * Returns a non-NULL pointer to a heap allocated node struct and
 * returns a NULL pointer if the node initialisation is unsuccessful.
 */
struct node *create_node(int value);

/*
 * Function that outputs the data field of each node struct that
 * follows the provided head pointer. `(end)' is used to indicate the
 * end of the list.
 *
 * This function does not return any values.
 */
void print_list(struct node *list_head);

/*
 * Function which de-allocates (frees) the memory allocated in the
 * provided (sub)list.
 *
 * This function does not return any values. This function has the
 * side-effect of making any pointer that was stored in the input
 * list to not be available to this process and thus causes a
 * segmentation fault if an attempt to dereference it is made
 * (also referred to as a `use-after-free error')
 */
void free_list(struct node *list_head);

/*
 * Function which returns a newly created linked list containing all
 * of the even values in the provided list.
 *
 * Returns a non-NULL pointer to a newly created linked list containing
 * all of the even values in the input linked list.
 */
struct node *get_all_even_values(struct node *list);

/*
 * Function which returns a newly created linked list containing all
 * of the odd values in the provided list.
 *
 * Returns a non-NULL pointer to a newly created linked list containing
 * all of the odd values in the input linked list.
 */
struct node *get_all_odd_values(struct node *list);

#endif // LIST_H
