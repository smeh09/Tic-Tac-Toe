#include <stdio.h>

static int board[3][3];

void emptyBrd();
void renderBrd();

int main() {
  char playing = 'Y';
  int pos;
  char validPos = 'N';

  if (playing == 'Y') {
    emptyBrd();
  }

  while (playing == 'Y') {
    validPos = 'N';
    while (validPos == 'N') {
      renderBrd();

      printf("Please enter where you want to place X ");
      scanf("%d", &pos);

      for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
          if (pos == board[y][x]) {
            board[y][x] = 100;
            validPos = 'Y';
          }
        }
      }
    }

    validPos = 'N';
    while (validPos == 'N') {
      renderBrd();

      printf("Please enter where you want to place O ");
      scanf("%d", &pos);

      for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
          if (pos == board[y][x]) {
            board[y][x] = 200;
            validPos = 'Y';
          }
        }
      }
    }
  }
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
  printf("\n");
  
  for (int y = 0; y < 3; y++) {
    printf("| ");
    for (int x = 0; x < 3; x++) {
      if (board[y][x] != 100 && board[y][x] != 200) {
        printf("%d | ", board[y][x]);
      } else if (board[y][x] == 100) {
        printf("X | ");
      } else if (board[y][x] == 200) {
        printf("O | ");
      }
    }
    if (y != 2) {
      printf("\n --- --- ---\n");
    } else {
      printf("\n");
    }
  }

  printf("\n");
}
