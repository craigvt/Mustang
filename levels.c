#include "levels.h"

void load_level(Game_t *game, Block_t grid[ROWS][COLS])
{
    switch(game->current_level)
    {
        case 0:
        {
            load_level_1(grid);
            break;
        }
    }
}

void load_level_1(Block_t grid[ROWS][COLS])
{
    // block types
    grid[0][0].type = 0; grid[0][1].type = 0; grid[0][2].type = 5; grid[0][3].type = 0; grid[0][4].type = 0; grid[0][5].type = 0;
    grid[1][0].type = 0; grid[1][1].type = 1; grid[1][2].type = 1; grid[1][3].type = 1; grid[1][4].type = 2; grid[1][5].type = 0;
    grid[2][0].type = 0; grid[2][1].type = 2; grid[2][2].type = 2; grid[2][3].type = 1; grid[2][4].type = 2; grid[2][5].type = 0;
    grid[3][0].type = 0; grid[3][1].type = 3; grid[3][2].type = 1; grid[3][3].type = 3; grid[3][4].type = 3; grid[3][5].type = 0;
    grid[4][0].type = 0; grid[4][1].type = 2; grid[4][2].type = 4; grid[4][3].type = 1; grid[4][4].type = 1; grid[4][5].type = 5;
    grid[5][0].type = 0; grid[5][1].type = 1; grid[5][2].type = 2; grid[5][3].type = 2; grid[5][4].type = 1; grid[5][5].type = 0;
    grid[6][0].type = 0; grid[6][1].type = 2; grid[6][2].type = 3; grid[6][3].type = 1; grid[6][4].type = 2; grid[6][5].type = 0;
    grid[7][0].type = 0; grid[7][1].type = 3; grid[7][2].type = 2; grid[7][3].type = 3; grid[7][4].type = 1; grid[7][5].type = 0;
    grid[8][0].type = 0; grid[8][1].type = 6; grid[8][2].type = 0; grid[8][3].type = 0; grid[8][4].type = 0; grid[8][5].type = 0;

    // key block
    grid[8][1].pos = 1;

    // first block
    grid[7][1].first_block = TRUE;
    grid[7][1].pos = 4;

    // power blocks
    grid[0][2].pos = 3;
    grid[4][5].pos = 4;
}
