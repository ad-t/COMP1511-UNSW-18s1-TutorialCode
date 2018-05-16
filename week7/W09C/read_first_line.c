/*
 * Write C code to read in the first line of a file named 
 * data.txt and display it on the screen. 
 */

#include <stdio.h>
#include <stdlib.h>

#define FILE_TO_READ_FROM "data.txt"
#define MAX_LINE_LENGTH 4096

int main (int argc, char * argv[]) {

  char file_contents[MAX_LINE_LENGTH] = { 0 };

  FILE *data_fd = fopen(FILE_TO_READ_FROM, "r");
  if (data_fd == NULL) {
    printf("Error in opening %s\n", FILE_TO_READ_FROM);
    return EXIT_FAILURE;
  }
  
  if (fgets(file_contents, MAX_LINE_LENGTH, data_fd) != NULL) {
    printf("%s", file_contents);
  } else {
    printf("Error in reading from %s\n", FILE_TO_READ_FROM);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
