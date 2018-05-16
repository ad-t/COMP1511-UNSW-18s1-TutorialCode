/*
 * Write C to read in a string from a user and write it to a file 
 * called data.txt. If the file data.txt exists, it should append 
 * the line of text to the end of the file. 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 4096
#define DATA_FILE "data.txt"

int main (int argc, char * argv[]) {
  
  char line[MAX_LINE_LENGTH] = { 0 };

  FILE *data_fd = fopen(DATA_FILE, "a");
  if (data_fd == NULL) {
    printf("Error in opening %s!\n", DATA_FILE);
    return EXIT_FAILURE;
  }

  if (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
    fprintf(data_fd, "%s", line);
    fclose(data_fd);
  } else {
    printf("Error in writing to file %s\n", DATA_FILE);
    fclose(data_fd);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
