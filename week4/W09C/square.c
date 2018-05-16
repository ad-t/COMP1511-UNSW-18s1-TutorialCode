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
        // even row
        if (column % 2 == 0) {
          printf("*");
        } else {
          printf("-");
        }
      } else {
        // odd row
        if (column % 2 != 0) {
          printf("*");
        } else {
          printf("-");
        }
      }

      column = column + 1;
    }
    printf("\n");
    row = row + 1;
  }

  return 0;
}
