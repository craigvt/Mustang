#include "common.h"
#include "data.h"
#include "game.h"
#include "grid.h"
#include "input.h"
#include "levels.h"
#include "render.h"
#include "start.h"
#include "system.h"
#include "ui.h"
#include "update.h"

int main( int argc, char* args[] )
{
    // -------------------
    // initialize

    srand(time(NULL));

    SDL_t sdl;
    init_sdl(&sdl);

    Render_t render;
    init_render(&sdl, &render);

    Game_t game;
    init_game(&game);

    Start_t start;
    init_start(&start);

    UI_t ui;
    init_ui(&ui);
    
    Input_t input;

    Block_t grid[ROWS][COLS];
    load_level(&game, grid);
    init_grid(&game, grid);

    reset_path(grid);
    update_path(&game, grid);
    update_block_textures(grid);

    while(game.running)
    {
        // ---------------------------------
        // input

        while(SDL_PollEvent(&input.event))
        {
            MAIN_input(&sdl, &render, &game, &start, &input, &ui, grid);
        }

        // ---------------------------------
        // update

        MAIN_update(&game, &input, &ui, grid);

        // ---------------------------------
        // render

        MAIN_render(&sdl, &render, &game, &start, &input, &ui, grid);

    }

    // ---------------------------------
    // clean up

    SDL_DestroyTexture(render.atlas);
    SDL_DestroyTexture(render.bgTarget);
    SDL_DestroyTexture(render.stageTarget);
    SDL_DestroyRenderer(sdl.renderer);
    SDL_DestroyWindow(sdl.window);
    SDL_Quit();

    return 0;
}
