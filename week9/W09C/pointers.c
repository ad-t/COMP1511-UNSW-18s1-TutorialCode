#include <stdio.h>

void addOne(int *variable);

int main (void) {

  int age = 25;
  printf("age before addOne: %d\n", age);
  addOne(&age);
  printf("age after addOne: %d\n", age);

  return 0;
}

void addOne(int *variable) {
  printf("age before addOne (inside the function): %d\n", *variable);
  *variable += 1;
  printf("age after addOne (inside the function): %d\n", *variable);
}
