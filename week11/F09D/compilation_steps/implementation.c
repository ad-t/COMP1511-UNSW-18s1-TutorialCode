// Simple implementation of `cat` to demonstrate
// the process of compiling different files
// together

#include "header.h"

int get_line(FILE *stream, char *destination) {
  if (fgets(destination, MAX_INPUT_SIZE, stream) != NULL) {
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}
