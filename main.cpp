#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

// TODO: use a dynamic 2d array that doesn't rely on const
const int x = 9;
const int y = 9;
int numMines = 10;

// TODO: add functionality to the setDifficulty and selectDifficulty functions
// switched const int numMines = 10 to int numMines = 10 for mutability
void setDifficulty(int setting) {
  switch(setting) {
    // 9x9 10 mines
    case 1:
      numMines = 10;
      break;
    // 16x16 40 mines
    case 2:
      numMines = 40;
      break;
    // 16x30 99 mines
    case 3:
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

void setupBoard(char board[x][y], bool visible[x][y]) {
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      board[i][j] = '.';
      visible[i][j] = false;
    }
  }
}

// TODO: create better mine placement algorithm
void placeMines(char board[x][y]) {
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

void repositionMine(char board[x][y], int cursorX, int cursorY) {
  bool mineMoved = false;
  srand(time(0));

  while(!mineMoved){
    int randX = rand() % x;
    int randY = rand() % y;
    if(randX != cursorX || randY != cursorY){
      if (board[randX][randY] != 'M') {
        board[randX][randY] = 'M';
        mineMoved = true;
      }
    }
  }
}

void placeNumbers(char board[x][y], int x, int y) {
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

void printBoard(char board[x][y], bool visible[x][y], bool flagged[x][y], int cursorX, int cursorY) {
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

// TODO: test first move function
void firstMove(char board[x][y], bool visible[x][y], int cursorX, int cursorY) {
  int offsetX[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
  int offsetY[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
  int numOffsets = sizeof(offsetX) / sizeof(offsetX[0]);

  if(board[cursorX][cursorY] == 'M'){
    repositionMine(board, cursorX, cursorY);
    board[cursorX][cursorY] == '.';
  }

   for(int i = 0; i < numOffsets; i++) {
    int offsetXValue = offsetX[i];
    int offsetYValue = offsetY[i];

    int newX = cursorX + offsetXValue;
    int newY = cursorY + offsetYValue;

    if (newX >= 0 && newX < x && newY >= 0 && newY < y && !visible[newX][newY] && board[newX][newY] != 'M') {
      visible[newX][newY] = true;
    }
  }
}

int main(int argc, char** argv) {
  /*
  initscr();
  selectDifficulty();
  endwin();
  */

  char board[x][y];
  bool visible[x][y];
  setupBoard(board, visible);
  placeMines(board);
  placeNumbers(board, x, y);
  bool start = true;
  bool flagged[x][y];

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  int cursorX = 0;
  int cursorY = 0;

  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      flagged[i][j] = false;
    }
  }

  while(true) {
    erase();
    printBoard(board, visible, flagged, cursorX, cursorY);
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
          firstMove(board, visible, cursorX, cursorY);
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