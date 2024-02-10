#include "settings.h"

int x = 9;
int y = 9;
int numMines = 10;

void setDifficulty(int setting) {
  switch(setting) {
    // 9x9 10 mines
    case 1:
      x = 9;
      y = 9;
      numMines = 10;
      break;
    // 16x16 40 mines
    case 2:
      x = 16;
      y = 16;
      numMines = 40;
      break;
    // 16x30 99 mines
    case 3:
      x = 16;
      y = 30;
      numMines = 99;
      break;
    default:
      break;
  }
}

void selectDifficulty() {
  printw("Minesweeper \nchoose a difficulty [1-3]: \n");
  switch(getch()){
    case '1':
      setDifficulty(1);
      break;
    case '2':
      setDifficulty(2);
      break;
    case '3':
      setDifficulty(3);
      break;
    default:
      setDifficulty(1);
      break;
  }
}