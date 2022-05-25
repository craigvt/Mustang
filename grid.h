#ifndef GRID_H
#define GRID_H

#include "common.h"
#include "data.h"

void init_grid(Game_t *game, Block_t grid[ROWS][COLS]);
void reset_path(Block_t grid[ROWS][COLS]);
void update_path(Game_t *game, Block_t grid[ROWS][COLS]);
void update_block_pos(Block_t grid[ROWS][COLS], Input_t *input);
void update_block_textures(Block_t grid[ROWS][COLS]);

#endif /* GRID_H */