#ifndef LEVELS_H
#define LEVELS_H

#include "common.h"
#include "data.h"

void load_level(Game_t *game, Block_t grid[ROWS][COLS]);
void load_level_1(Block_t grid[ROWS][COLS]);

#endif /* LEVELS_H */