#include <stdio.h>

int main (void) {
  
  // TODO: Implement the pass_fail functionality outlined in the specification.
  
  printf("Please enter your mark: ");
  int age = 0;
  scanf("%d", &age);

  if (age >= 50 && age <= 100) {
    printf("PASS\n");
  } else if (age >= 0 && age <= 49) {
    printf("FAIL\n");
  } else {
    printf("ERROR\n");
  }

  printf("Your mark was: %d\n", age);

  return 0;
}
