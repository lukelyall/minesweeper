#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

const int x = 9;
const int y = 9;
const int numMines = 10;

void setupBoard(char board[x][y], bool visible[x][y]) {
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      board[i][j] = '.';
      visible[i][j] = false;
    }
  }
}

void placeMines(char board[x][y]) {
  srand(time(0));
  int minesPlaced = 0;
  while (minesPlaced < numMines) {
    int randX = rand() % x;
    int randY = rand() % y;
    if (board[randX][randY] != '*') {
      board[randX][randY] = '*';
      minesPlaced++;
    }
  }
}

void printBoard(char board[x][y], bool visible[x][y], int cursorX, int cursorY) {
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      if (i == cursorX && j == cursorY) {
        attron(A_REVERSE);
      }
      if (visible[i][j]) {
        printw("%c ", board[i][j]);
      } else {
        printw("# ");
      }
      if (i == cursorX && j == cursorY) {
        attroff(A_REVERSE);
      }
    }
    printw("\n");
  }
}

int main(int argc, char** argv) {
    char board[x][y];
    bool visible[x][y];
    setupBoard(board, visible);
    placeMines(board);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int cursorX = 0;
    int cursorY = 0;

    while(true) {
      clear();
      printBoard(board, visible, cursorX, cursorY);
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
        case 'z':
          visible[cursorX][cursorY] = true;
          break;
        case 'q':
          endwin();
          return 0;
      }
    }
}