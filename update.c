#include "update.h"

void MAIN_update(Game_t *game, Input_t *input, UI_t *ui, Block_t grid[ROWS][COLS])
{
    switch(game->state)
    {
        case INTRO:
            break;
        
        case START:
            break;

        case PLAY:
            if(game->block_touched == TRUE){
                update_block_pos(grid, input);
                reset_path(grid);
                update_path(game, grid);
                update_block_textures(grid);
                win_check(game, grid);
                
                game->block_touched = FALSE;
            }
            break;

        case LEVEL_WON:
            if(game->reset_level == TRUE){
                init_game(game);
                load_level(game, grid);
                init_grid(game, grid);
                init_ui(ui);
                reset_path(grid);
                update_path(game, grid);
                update_block_textures(grid);

                game->reset_level = FALSE;
            }
            break;

        case MENU:
            break;
    }
}