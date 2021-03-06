#include <stdio.h>

static int board[3][3];

void emptyBrd();
void renderBrd();
int checkWin();

int main() {
  int pos;
  char validPos = 'N';
  int leftpos = 9;
  char xWon;
  char oWon;
  int gameFinished = 1;

  emptyBrd();

  while (gameFinished != 0) {
    validPos = 'N';
    while (validPos == 'N' && leftpos > 0) {
      renderBrd();

      printf("Please enter where you want to place X ");
      scanf("%d", &pos);

      for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
          if (pos == board[y][x]) {
            board[y][x] = 100;
            validPos = 'Y';
            leftpos--;
          }
        }
      }
    }

    xWon = checkWin(100);
    if (xWon == 0) {
      renderBrd();
      printf("X WON!! ");
      gameFinished = 0;
      break;
    }

    validPos = 'N';
    while (validPos == 'N' && leftpos > 0) {
      renderBrd();

      printf("Please enter where you want to place O ");
      scanf("%d", &pos);

      for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
          if (pos == board[y][x]) {
            board[y][x] = 200;
            validPos = 'Y';
            leftpos--;
          }
        }
      }
    }
    oWon = checkWin(200);
    if (oWon == 0) {
      renderBrd();
      printf("O WON!!");
      gameFinished = 0;
      break;
    }
  }

  return 0;
}

int checkWin(int value) {
  int vc = 1;
  int hc = 1;
  int drc = 1;
  int dlc = 1;

  if ((board[0][0] == value && board[1][0] == value && board[2][0] == value) ||
  (board[0][1] == value && board[1][1] == value && board[2][1] == value) ||
  (board[0][2] == value && board[1][2] == value && board[2][2] == value))
   {
     vc = 0;
   }

  if ((board[0][0] == value && board[0][1] == value && board[0][2] == value) ||
  (board[1][0] == value && board[1][1] == value && board[1][2] == value) ||
  (board[2][0] == value && board[2][1] == value && board[2][2] == value))
  {
    hc = 0;
  }

  if (board[0][0] == value && board[1][1] == value && board[2][2] == value)
  {
    drc = 0;
  }

  if (board[0][2] == value && board[1][1] == value && board[2][0] == value)
  {
    dlc = 0;
  }

  if (dlc == 0 || drc == 0 || hc == 0 || vc == 0) {
    return 0;
  }

  return 1;
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
