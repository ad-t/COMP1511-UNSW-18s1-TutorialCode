/*
 * Write a program line_length.c which reads lines from its 
 * input and prints how many characters each line contains.
 *
 * The only functions you can use are fgets and printf.
 *
 * You can assume lines contain at most 4096 characters. 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 4096

int main (int argc, char * argv[]) {

  char user_input[MAX_LINE_LENGTH];
  unsigned int input_index = 0;
  unsigned int string_length = 0;

  while (fgets(user_input, MAX_LINE_LENGTH, stdin) != NULL) {
    input_index = 0;
    string_length = 0;
    while (user_input[input_index] != '\0') {
      if (user_input[input_index] >= ' ' && user_input[input_index] <= '~') {
        string_length += 1;
      }
      input_index += 1;
    }
    printf("line %d characters long\n", string_length);
  }

  return EXIT_SUCCESS;
}
