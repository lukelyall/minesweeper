#ifndef SETTINGS_H
#define SETTINGS_H

#include <ncurses.h>
#include <vector>
#include <ctime>
#include <cstdlib>

extern int x;
extern int y;
extern int numMines;

void setDifficulty(int setting);
void selectDifficulty();

#endif