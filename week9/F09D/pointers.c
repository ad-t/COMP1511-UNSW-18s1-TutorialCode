#include <stdio.h>

void addOne(int *value);

int main (void) {
  int x = 20;
  printf("before addOne: %d\n", x);
  addOne(&x);
  printf("after addOne: %d\n", x);
  return 0;
}

void addOne(int *value) {
  printf("before (during) addOne: %d\n", *value);
  *value += 1;
  printf("after (during) addOne: %d\n", *value);
}
