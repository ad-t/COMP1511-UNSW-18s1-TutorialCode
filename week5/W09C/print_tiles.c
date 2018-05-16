#include <stdio.h>
#include <stdlib.h>

#define N_TILES 4

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










void print_tiles(int tiles[N_TILES]) {
  int tile_counter = 0;
  while (tile_counter < N_TILES) {
    printf("%d", tiles[tile_counter]);
    if (tile_counter + 1 != N_TILES) {
      printf(" ");
    }
    tile_counter = tile_counter + 1;
  }
  printf("\n");
}
