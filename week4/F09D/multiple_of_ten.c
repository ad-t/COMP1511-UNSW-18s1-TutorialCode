#include <stdio.h>

int main (int argc, char **argv) {
  int start = 0;
  int end = 0;
  printf("Enter start: ");
  scanf("%d", &start);
  printf("Enter finish: ");
  scanf("%d", &end);

  if (start % 10 == 0) {
    printf("%d\n", start);
  }

  int working_number = (start / 10) + 1;

  while (working_number <= end / 10) {
    printf("%d\n", working_number * 10);
    working_number = working_number + 1;
  }

  return 0;
}
