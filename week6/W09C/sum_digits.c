/* Write a program sum_digits.c which reads 
 * characters from its input and counts digits.
 * 
 * When the end of input is reached it should 
 * print a count of how many digits occurred 
 * in its input and their sum.
 *
 * The only functions you can use are getchar and printf.
 */

#include <stdio.h>
#include <stdlib.h>

int main (void) {

  unsigned int digit_count = 0;
  int sum_of_digits = 0;

  int input_character;

  input_character = getchar();

  while (input_character != EOF) {
    if (input_character >= '0' && input_character <= '9') {
      digit_count += 1;
      sum_of_digits += input_character - '0';
    }
    input_character = getchar();
  }

  printf("Input contained %d digits which summed to %d\n", digit_count, sum_of_digits);

  /* 
   * What should I do next? What does getchar() do? 
   *
   * Time to check out the manual! 
   *
   * Have we made any assumptions that we should not have?
   */

  // TODO: Finish the implementation of sum_digits

  return EXIT_SUCCESS;
}
