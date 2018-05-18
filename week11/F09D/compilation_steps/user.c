#include "header.h"

int main (void) {
  char input_buffer[MAX_INPUT_SIZE] = { 0 };
  while (get_line(stdin, input_buffer) == EXIT_SUCCESS) {
    if (input_buffer[strlen(input_buffer)-1] == '\n') {
      printf("[CAT OUTPUT]: %s", input_buffer);
    } else {
      printf("\n[CAT OUTPUT]: %s\n", input_buffer);
    }
  }
  return EXIT_SUCCESS;
}
