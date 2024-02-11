#include "../includes/logic.h"

void repositionMine(std::vector<std::vector<char>>&board, int x, int y, int cursorX, int cursorY) {
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

// TODO: test first move function
void firstMove(std::vector<std::vector<char>>&board, std::vector<std::vector<bool>>&visible, int x, int y, int cursorX, int cursorY) {
  int offsetX[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
  int offsetY[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
  int numOffsets = sizeof(offsetX) / sizeof(offsetX[0]);

  if(board[cursorX][cursorY] == 'M'){
    repositionMine(board, x, y, cursorX, cursorY);
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