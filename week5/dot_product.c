#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define VECTOR_LENGTH 5

int dot_product(int vector1[VECTOR_LENGTH], int vector2[VECTOR_LENGTH]);

int main (int argc, char **argv) {

  int vector_one[VECTOR_LENGTH] = {1 3 1 3 2}; 
  int vector_two[VECTOR_LENGTH] = {2 1 2 1 2};

  assert(dot_product(vector_one, vector_two) == 14);

  return EXIT_SUCCESS;
}
