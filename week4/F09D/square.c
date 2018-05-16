#include <stdio.h>

int main(void) {
  int number;
  int row, column;

  // Obtain input
  printf("Enter size: ");
  scanf("%d", &number);

  row = 1;
  while (row <= number) {
    column = 1;
    while (column <= number) {
      if (row % 2 == 0) {
        if (column % 2 != 0) {
          printf("*");
        } else {
          printf("_");
        }
      } else {
        if (column % 2 == 0) {
          printf("*");
        } else {
          printf("_");
        }
      }
      column = column + 1;
    }
    printf("\n");
    row = row + 1;
  }

  return 0;
}
