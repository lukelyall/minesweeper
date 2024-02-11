#include "../includes/board.h"

// TODO: create better mine placement algorithm
void placeMines(std::vector<std::vector<char>>&board, int x, int y, int numMines) {
  srand(time(0));
  int minesPlaced = 0;
  while (minesPlaced < numMines) {
    int randX = rand() % x;
    int randY = rand() % y;
    if (board[randX][randY] != 'M') {
      board[randX][randY] = 'M';
      minesPlaced++;
    }
  }
}

void placeNumbers(std::vector<std::vector<char>>&board, int x, int y) {
  int offsetX[8] = {0, 0, 1, -1, 1, -1, 1, -1};
  int offsetY[8] = {1, -1, 0, 0, 1, 1, -1, -1};
  int numOffsets = sizeof(offsetX) / sizeof(offsetX[0]);

  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      if(board[i][j] != 'M') {
        int nearbyMines = 0;
        for(int k = 0; k < numOffsets; k++) {
          int newX = i + offsetX[k];
          int newY = j + offsetY[k];
          if(newX >= 0 && newX < x && newY >= 0 && newY < y && board[newX][newY] == 'M') {
            nearbyMines++;
          }
        }
        board[i][j] = '0' + nearbyMines;
      }
    }
  }
}

void printBoard(std::vector<std::vector<char>>&board, std::vector<std::vector<bool>>&visible, std::vector<std::vector<bool>>&flagged, int x, int y, int cursorX, int cursorY) {
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      if (i == cursorX && j == cursorY) {
        attron(A_REVERSE);
      }
      if (visible[i][j]) {
        printw("%c ", board[i][j]);
      } 
      else if (flagged[i][j]) {
        printw("F ");
      }
      else {
        printw("# ");
      }
      if (i == cursorX && j == cursorY) {
        attroff(A_REVERSE);
      }
    }
    printw("\n");
  }
}