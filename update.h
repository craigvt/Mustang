#ifndef UPDATE_H
#define UPDATE_H

#include "common.h"
#include "data.h"
#include "game.h"
#include "levels.h"
#include "ui.h"
#include "grid.h"

void MAIN_update(Game_t *game, Input_t *input, UI_t *ui, Block_t grid[ROWS][COLS]);

#endif /* UPDATE_H */