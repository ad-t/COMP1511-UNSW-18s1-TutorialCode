#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[10];
};

int main (void) {
  struct student *adam = (struct student *) malloc(sizeof(struct student) * 1); 
  // use this struct for really cool things
  free(adam);
  return 0;
}
