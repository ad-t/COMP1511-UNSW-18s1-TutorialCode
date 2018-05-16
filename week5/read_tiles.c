#include <stdio.h>
#include <stdlib.h>

int read_tiles(int tiles[N_TILES]);

int main (int argc, char **argv) {

  int array_of_tiles[N_TILES] = { 0 };

  read_tiles(array_of_tiles);
  
  int tile_counter = 0;
  while (tile_counter < N_TILES) {
    printf("%d", array_of_tiles[tile_counter]);
    if (tile_counter + 1 != N_TILES) {
      printf(" ");
    }
  }

  return EXIT_SUCCESS;
}
