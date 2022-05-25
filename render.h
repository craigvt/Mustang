#ifndef RENDER_H
#define RENDER_H

#include "common.h"
#include "data.h"

void init_render(SDL_t *sdl, Render_t *render);
void MAIN_render(SDL_t *sdl, Render_t *render, Game_t *game, Start_t *start, Input_t *input, UI_t *ui, Block_t grid[ROWS][COLS]);
void render_intro(SDL_t *sdl, Render_t *render, Start_t *start);
void render_start(SDL_t *sdl, Render_t *render, Start_t *start);
void render_ui(SDL_t *sdl, Render_t *render, Game_t *game, UI_t *ui);
void render_grid(SDL_t *sdl, Render_t *render, Block_t grid[ROWS][COLS]);
void render_menu(SDL_t *sdl, Render_t *render, UI_t *ui);
void render_notice(SDL_t *sdl, Render_t *render, UI_t *ui);

#endif /* RENDER_H */