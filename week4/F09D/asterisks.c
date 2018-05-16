#include <stdio.h>

int main (int argc, char **argv) {

  printf("Please enter an integer: ");
  int n_asterices = 0;
  scanf("%d", &n_asterices);
  int asterisk_count = 0;
  while (asterisk_count < n_asterices) {
    printf("*\n");
    asterisk_count = asterisk_count + 1;
  }

  return 0;
}
