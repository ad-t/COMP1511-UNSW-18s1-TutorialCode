#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 50

struct comp1511_student {
  char name[MAX_NAME_SIZE];
  unsigned int age;
  unsigned int ass1_mark;
};

int main (void) {

  struct comp1511_student adam; 
  adam.age = 21;
  char *adams_name = "adam";
  strncpy(adam.name, adams_name, strlen(adams_name) + 1);
  adam.ass1_mark = 75;

  struct comp1511_student andrew; 
  andrew.age = 25;
  char *andrew_name = "andrew";
  strncpy(andrew.name, andrew_name, strlen(andrew_name) + 1);
  andrew.ass1_mark = 99;
  printf("student name: %s, age: %d, ass1_mark: %d\n", adam.name, adam.age, adam.ass1_mark);
  printf("student name: %s, age: %d, ass1_mark: %d\n", andrew.name, andrew.age, andrew.ass1_mark);

  return 0;
}
