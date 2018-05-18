#include <string.h>

int mars_bars_on_board(struct bot *b) {
  if (b == NULL) {
    return 0;
  }
  if (strcmp(b->fruit, "Mars Bars") == 0) {
    return b->fruit_kg;
  }
  return 0;
}

int mars_bars_for_sale(struct bot *b) {
  if (b == NULL) {
    return 0;
  }
  if (strcmp(b->location->fruit, "Mars Bars") == 0) {
    if (b->location->price < 0) {
      return b->location->quantity;
    } else {
      return 0;
    }
  }
  return 0;
}
