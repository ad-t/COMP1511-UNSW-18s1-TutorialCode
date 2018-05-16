#include <stdio.h>

int main (void) {
  
  // TODO: Implement the pass_fail functionality outlined in the specification.
  
  // prompt user to enter their mark
  printf("Please enter your mark: ");
  int mark = 0;
  // collect the input data from the user
  scanf("%d", &mark);
  // check the input and output the appropriate response
  if (mark >= 50 && mark <= 100) {
    printf("PASS\n");
  } else if (mark <= 49 && mark >= 0) {
    printf("FAIL\n");
  } else {
    printf("ERROR\n");
  }

  printf("You entered: %d, %d %d %d\n", mark, 1300, 655, 06);

  return 0;
}
