#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define VECTOR_LENGTH 10
#define TRUE 1
#define FALSE 0

int array_contains(int vector[], int size, int requested_value);

int main (int argc, char **argv) {

  int vector[VECTOR_LENGTH];
  for (int i = 0; i < VECTOR_LENGTH; i++) {
    vector[i] = i*i + 3;
  }

  assert(array_contains(vector, VECTOR_LENGTH, vector[2]) == TRUE);
  assert(array_contains(vector, VECTOR_LENGTH, vector[3]) == TRUE);
  assert(array_contains(vector, VECTOR_LENGTH, vector[4]) == TRUE);
  assert(array_contains(vector, VECTOR_LENGTH, 9) == FALSE);
  assert(array_contains(vector, VECTOR_LENGTH, vector[8]) == TRUE);
  assert(array_contains(vector, VECTOR_LENGTH, 22) == FALSE);
  assert(array_contains(vector, VECTOR_LENGTH, 105) == FALSE);
  printf("Awesome!\n");

  return EXIT_SUCCESS;
}

int array_contains(int vector[], int size, int requested_value) {
  if (size <= 0) {
    return FALSE;
  }
  int array_index = 0;
  while (array_index < size) {
    if (requested_value == vector[array_index]) {
      return TRUE;
    }
    array_index = array_index + 1;
  }
  return FALSE;
}
