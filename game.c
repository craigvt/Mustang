#include "game.h"

void init_game(Game_t *game)
{
	game->state = PLAY;
    game->running = TRUE;
    game->current_level = 0;
    game->power_blocks = 0;

    game->reset_level = FALSE;
    game->block_touched = FALSE;
}

void win_check(Game_t *game, Block_t grid[ROWS][COLS])
{
    int active_power_blocks = 0;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(grid[i][j].type == 5 && grid[i][j].active == TRUE)
            {
                active_power_blocks++;
            }
        }
    }

    if(active_power_blocks == game->power_blocks)
    {
        game->state = LEVEL_WON;
    }
}