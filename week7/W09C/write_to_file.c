/*
 * Write C code to read in a string from a user and write it to a 
 * file called data.txt. If the file data.txt exists, it should be 
 * overwritten 
 */

#include <stdio.h>
#include <stdlib.h>

#define FILE_TO_READ_FROM "data.txt"
#define MAX_LINE_LENGTH 4096

int main (int argc, char * argv[]) {

  char file_contents[MAX_LINE_LENGTH] = { 0 };

  FILE *data_fd = fopen(FILE_TO_READ_FROM, "w");
  if (data_fd == NULL) {
    printf("Error in opening %s\n", FILE_TO_READ_FROM);
    return EXIT_FAILURE;
  }
  
  if (fgets(file_contents, MAX_LINE_LENGTH, stdin) != NULL) {
    fprintf(data_fd, "%s", file_contents);
    fclose(data_fd);
  } else {
    printf("Error in reading from %s\n", FILE_TO_READ_FROM);
    fclose(data_fd);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
