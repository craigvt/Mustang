#ifndef INPUT_H
#define INPUT_H

#include "common.h"
#include "data.h"

void MAIN_input(SDL_t *sdl, Render_t *render, Game_t *game, Start_t *start, Input_t *input, UI_t *ui, Block_t grid[ROWS][COLS]);

#endif /* INPUT_H */