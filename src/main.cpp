#include "../includes/board.h"
#include "../includes/logic.h"
#include "../includes/settings.h"

#include <iostream>

int main(int argc, char** argv) {
  initscr();
  selectDifficulty();
  endwin();

  std::vector<std::vector<char>> board(x, std::vector<char>(y, '.'));
  std::vector<std::vector<bool>> visible(x, std::vector<bool>(y, false));
  std::vector<std::vector<bool>> flagged(x, std::vector<bool>(y, false));

  bool start = true;

  placeMines(board, x, y, numMines);
  placeNumbers(board, x, y);

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  int cursorX = 0;
  int cursorY = 0;

  board.resize(x, std::vector<char>(y, '.'));
  visible.resize(x, std::vector<bool>(y, false));
  flagged.resize(x, std::vector<bool>(y, false));

  while(true) {
    erase();
    printBoard(board, visible, flagged, x, y, cursorX, cursorY);
    int ch = getch();
    switch(ch) {
      case KEY_UP:
        if(cursorX > 0)
            cursorX--;
        break;
      case KEY_DOWN:
        if(cursorX < x - 1)
            cursorX++;
        break;
      case KEY_LEFT:
        if(cursorY > 0)
            cursorY--;
        break;
      case KEY_RIGHT:
        if(cursorY < y - 1)
            cursorY++;
        break;
      case 'd':
        if(start == true) {
          firstMove(board, visible, x, y, cursorX, cursorY);
          start = false;
        }
        if (board[cursorX][cursorY] == 'M' & !flagged[cursorX][cursorY]) {
          for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
              visible[i][j] = true;
            }
          }
        }
        if (!visible[cursorX][cursorY] & !flagged[cursorX][cursorY]) {
          visible[cursorX][cursorY] = true;
        }
        break;
      case 'f':
        if (!visible[cursorX][cursorY]) {
          flagged[cursorX][cursorY] = !flagged[cursorX][cursorY];
        }
        break;
      case 'q':
        endwin();
        return 0;
    }
  }
}