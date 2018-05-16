#include <stdio.h>
#include <stdlib.h>

void print_tiles(int tiles[N_TILES]);

int main (int argc, char **argv) {

  int tiles1[N_TILES] = {1, 2, 3, 4};
  int tiles2[N_TILES] = {2, 3, 4, 5};
  int tiles3[N_TILES] = {8, 8, 9, 9};

  print_tiles(tiles1);
  print_tiles(tiles2);
  print_tiles(tiles3);

  return EXIT_SUCCESS;
}
