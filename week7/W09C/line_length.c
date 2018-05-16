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

  char line[MAX_LINE_LENGTH] = { 0 };
  unsigned int character_index;
  unsigned int string_length;

  while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
    character_index = 0;
    string_length = 0;
    while (line[character_index] != '\0') {
      if (line[character_index] >= ' ' && line[character_index] <= '~') {
        string_length += 1;
      }
      character_index += 1;
    }
    printf("line %d characters long\n", string_length);
  }

  return EXIT_SUCCESS;
}
