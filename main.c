#include <stdio.h>

static int board[3][3];

void emptyBrd();
void renderBrd();

int main() {
  emptyBrd();
  renderBrd();
}

void emptyBrd() {
  int c = 0;
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      c++;
      board[y][x] = c;
    }
  }
}

void renderBrd() {
  for (int y = 0; y < 3; y++) {
    printf("| ");
    for (int x = 0; x < 3; x++) {
      printf("%d | ", board[y][x]);
    }
    if (y != 2) {
      printf("\n --- --- ---\n");
    } else {
      printf("\n");
    }
  }
}
