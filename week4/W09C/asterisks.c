#include <stdio.h>

int main (int argc, char **argv) {

  printf("Please enter an integer: ");
  int asterisk_count = 0;
  scanf("%d", &asterisk_count);

  while (asterisk_count > 0) {
    printf("*\n");
    asterisk_count = asterisk_count - 1;
  }

  return 0;
}
