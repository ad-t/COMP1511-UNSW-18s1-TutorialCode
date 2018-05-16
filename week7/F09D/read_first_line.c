/*
 * Write C code to read in the first line of a file named 
 * data.txt and display it on the screen. 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 4096
#define DATA_FILE "data.txt"

int main (int argc, char * argv[]) {
  
  char line[MAX_LINE_LENGTH] = { 0 };

  FILE *data_fd = fopen(DATA_FILE, "r");
  if (data_fd == NULL) {
    printf("Error in opening %s!\n", DATA_FILE);
    return EXIT_FAILURE;
  }

  if (fgets(line, MAX_LINE_LENGTH, data_fd) != NULL) {
    printf("%s", line);
    fclose(data_fd);
  } else {
    printf("Error in reading from file %s\n", DATA_FILE);
    fclose(data_fd);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
