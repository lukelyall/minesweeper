#ifndef LOGIC_H
#define LOGIC_H

#include "settings.h"

void repositionMine(std::vector<std::vector<char>>&board, int x, int y, int cursorX, int cursorY);
void firstMove(std::vector<std::vector<char>>&board, std::vector<std::vector<bool>>&visible, int x, int y, int cursorX, int cursorY);

#endif