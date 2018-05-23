#ifndef LIST_H
#define LIST_H

struct node {
  struct node *next;
  int          data;
};

struct node *create_list(int initial_value);
void print_list(struct node *head_of_list);
void free_list(struct node *head_of_list);
struct node *sorted_insert(struct node *list, int value);

struct node *list_append(struct node *list1, struct node *list2);
struct node *strings_to_list(int len, char *strings[]);
struct node *merge_sorted(struct node *list1, struct node *list2);

#endif // LIST_H
