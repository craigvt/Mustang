#ifndef APP_H
#define APP_H

#include "common.h"
#include "data.h"

void init_game(Game_t *game);
void win_check(Game_t *game, Block_t grid[ROWS][COLS]);

#endif /* APP_H */