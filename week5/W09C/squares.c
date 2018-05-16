#include <stdio.h>
#include <stdlib.h>

#define AMOUNT_OF_SQUARES (15)

int main (int argc, char **argv) {

  int squares[AMOUNT_OF_SQUARES];
  int squares_index = 0;
  while (squares_index < AMOUNT_OF_SQUARES) {
    squares[squares_index] = squares_index * squares_index;
    printf("%d\n", squares[squares_index]);
    squares_index = squares_index + 1;
  }

  return EXIT_SUCCESS;
}
