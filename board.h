#ifndef BOARD_H
#define BOARD_H

#include "settings.h"

void placeMines(std::vector<std::vector<char>>&board, int x, int y, int numMines);
void placeNumbers(std::vector<std::vector<char>>&board, int x, int y);
void printBoard(std::vector<std::vector<char>>&board, std::vector<std::vector<bool>>&visible, std::vector<std::vector<bool>>&flagged, int x, int y, int cursorX, int cursorY);

#endif