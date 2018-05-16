#include <stdio.h>

int main (int argc, char **argv) {

  int beginning = 0;
  int end = 0;

  printf("Enter start: ");
  scanf("%d", &beginning);
  printf("Enter finish: ");
  scanf("%d", &end);

  int current_multiple = (beginning / 10) + 1;

  while (current_multiple <= end / 10) {
    printf("%d\n", current_multiple * 10);
    current_multiple = current_multiple + 1;
  }

  return 0;
}
