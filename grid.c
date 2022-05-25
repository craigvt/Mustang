#include "grid.h"

void init_grid(Game_t *game, Block_t grid[ROWS][COLS])
{
    int id_count = 1;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            grid[i][j].id = id_count;
            id_count++;

            if(grid[i][j].type == 6)
            {
                game->key_block = grid[i][j].id;
            }

            if(grid[i][j].type == 5)
            {
                game->power_blocks++;
            }

            if(grid[i][j].first_block != TRUE)
            {
                grid[i][j].first_block = FALSE;
            }

            grid[i][j].dst.w = TILE_SIZE;
            grid[i][j].dst.h = TILE_SIZE;
            grid[i][j].src.w = TILE_SIZE;
            grid[i][j].src.h = TILE_SIZE;

            grid[i][j].dst.x = j * TILE_SIZE;
            grid[i][j].dst.y = (i * TILE_SIZE) + TILE_SIZE;

            switch(grid[i][j].type)
            {
                case 0:
                {
                    grid[i][j].n = 0;
                    grid[i][j].e = 0;
                    grid[i][j].s = 0;
                    grid[i][j].w = 0;
                    grid[i][j].pos = 1;
                    break;
                }
                case 1:
                {
                    if(grid[i][j].first_block == FALSE)
                    {
                        grid[i][j].pos = rand() % ((4 - 1) + 1) + 1;
                    }
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            grid[i][j].n = 1;
                            grid[i][j].e = 1;
                            grid[i][j].s = 0;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 2:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 1;
                            grid[i][j].s = 1;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 3:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 0;
                            grid[i][j].s = 1;
                            grid[i][j].w = 1;
                            break;
                        }
                        case 4:
                        {
                            grid[i][j].n = 1;
                            grid[i][j].e = 0;
                            grid[i][j].s = 0;
                            grid[i][j].w = 1;
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    if(grid[i][j].first_block == FALSE)
                    {
                        grid[i][j].pos = rand() % ((3 - 1) + 1) + 1;
                    }
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            grid[i][j].n = 1;
                            grid[i][j].e = 0;
                            grid[i][j].s = 1;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 2:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 1;
                            grid[i][j].s = 0;
                            grid[i][j].w = 1;
                            break;
                        }
                        case 3:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 1;
                            grid[i][j].s = 0;
                            grid[i][j].w = 1;
                            break;
                        }
                    }
                    break;
                }
                case 3:
                {
                    if(grid[i][j].first_block == FALSE)
                    {
                        grid[i][j].pos = rand() % ((4 - 1) + 1) + 1;
                    }
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            grid[i][j].n = 1;
                            grid[i][j].e = 1;
                            grid[i][j].s = 1;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 2:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 1;
                            grid[i][j].s = 1;
                            grid[i][j].w = 1;
                            break;
                        }
                        case 3:
                        {
                            grid[i][j].n = 1;
                            grid[i][j].e = 0;
                            grid[i][j].s = 1;
                            grid[i][j].w = 1;
                            break;
                        }
                        case 4:
                        {
                            grid[i][j].n = 1;
                            grid[i][j].e = 1;
                            grid[i][j].s = 0;
                            grid[i][j].w = 1;
                            break;
                        }
                    }
                    break;
                }
                case 4:
                {
                    grid[i][j].pos = 1;
                    grid[i][j].n = 1;
                    grid[i][j].e = 1;
                    grid[i][j].s = 1;
                    grid[i][j].w = 1;
                    break;
                }
                case 5:
                {
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            grid[i][j].n = 1;
                            grid[i][j].e = 0;
                            grid[i][j].s = 0;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 2:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 1;
                            grid[i][j].s = 0;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 3:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 0;
                            grid[i][j].s = 1;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 4:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 0;
                            grid[i][j].s = 0;
                            grid[i][j].w = 1;
                            break;
                        }
                    }
                    break;
                }
                case 6:
                {
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            grid[i][j].n = 1;
                            grid[i][j].e = 0;
                            grid[i][j].s = 0;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 2:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 1;
                            grid[i][j].s = 0;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 3:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 0;
                            grid[i][j].s = 1;
                            grid[i][j].w = 0;
                            break;
                        }
                        case 4:
                        {
                            grid[i][j].n = 0;
                            grid[i][j].e = 0;
                            grid[i][j].s = 0;
                            grid[i][j].w = 1;
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}

void reset_path(Block_t grid[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            grid[i][j].active = FALSE;
            grid[i][j].in_path_que = FALSE;
        }
    }
}

void update_path(Game_t *game, Block_t grid[ROWS][COLS])
{
    int path_que[54] = {0};
    int next_slot = 1;

    path_que[0] = game->key_block;

    for(int x = 0; x < 54; x++)
    {
        int current_id = path_que[x];

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                int row_minus = i - 1;
                int row_plus = i + 1;
                int col_minus = j - 1;
                int col_plus = j + 1;

                if(grid[i][j].id == current_id)
                {
                    grid[i][j].in_path_que = TRUE;
                    grid[i][j].active = TRUE;

                    if(grid[i][j].e + grid[i][col_plus].w == 2 && grid[i][col_plus].in_path_que == FALSE)
                    {
                        path_que[next_slot] = grid[i][col_plus].id;
                        next_slot++;
                    }
                    if(grid[i][j].w + grid[i][col_minus].e == 2 && grid[i][col_minus].in_path_que == FALSE)
                    {
                        path_que[next_slot] = grid[i][col_minus].id;
                        next_slot++;
                    }
                    if(grid[i][j].n + grid[row_minus][j].s == 2 && grid[row_minus][j].in_path_que == FALSE)
                    {
                        path_que[next_slot] = grid[row_minus][j].id;
                        next_slot++;
                    }
                    if(grid[i][j].s + grid[row_plus][j].n == 2 && grid[row_plus][j].in_path_que == FALSE)
                    {
                        path_que[next_slot] = grid[row_plus][j].id;
                        next_slot++;
                    }
                }
            }
        }
    }
}

void update_block_pos(Block_t grid[ROWS][COLS], Input_t *input)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(grid[i][j].id == input->input_loc)
            {
                switch(grid[i][j].type)
                {
                    case 1:
                    {
                        switch(grid[i][j].pos)
                        {
                            case 1:
                            {
                                grid[i][j].pos = 2;
                                grid[i][j].n = 0;
                                grid[i][j].e = 1;
                                grid[i][j].s = 1;
                                grid[i][j].w = 0;
                                break;
                            }
                            case 2:
                            {
                                grid[i][j].pos = 3;
                                grid[i][j].n = 0;
                                grid[i][j].e = 0;
                                grid[i][j].s = 1;
                                grid[i][j].w = 1;
                                break;
                            }
                            case 3:
                            {
                                grid[i][j].pos = 4;
                                grid[i][j].n = 1;
                                grid[i][j].e = 0;
                                grid[i][j].s = 0;
                                grid[i][j].w = 1;
                                break;
                            }
                            case 4:
                            {
                                grid[i][j].pos = 1;
                                grid[i][j].n = 1;
                                grid[i][j].e = 1;
                                grid[i][j].s = 0;
                                grid[i][j].w = 0;
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        switch(grid[i][j].pos)
                        {
                            case 1:
                            {
                                grid[i][j].pos = 2;
                                grid[i][j].n = 0;
                                grid[i][j].e = 1;
                                grid[i][j].s = 0;
                                grid[i][j].w = 1;
                                break;
                            }
                            case 2:
                            {
                                grid[i][j].pos = 1;
                                grid[i][j].n = 1;
                                grid[i][j].e = 0;
                                grid[i][j].s = 1;
                                grid[i][j].w = 0;
                                break;
                            }
                            case 3:
                            {
                                grid[i][j].pos = 1;
                                grid[i][j].n = 1;
                                grid[i][j].e = 0;
                                grid[i][j].s = 1;
                                grid[i][j].w = 0;
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        switch(grid[i][j].pos)
                        {
                            case 1:
                            {
                                grid[i][j].pos = 2;
                                grid[i][j].n = 0;
                                grid[i][j].e = 1;
                                grid[i][j].s = 1;
                                grid[i][j].w = 1;
                                break;
                            }
                            case 2:
                            {
                                grid[i][j].pos = 3;
                                grid[i][j].n = 1;
                                grid[i][j].e = 0;
                                grid[i][j].s = 1;
                                grid[i][j].w = 1;
                                break;
                            }
                            case 3:
                            {
                                grid[i][j].pos = 4;
                                grid[i][j].n = 1;
                                grid[i][j].e = 1;
                                grid[i][j].s = 0;
                                grid[i][j].w = 1;
                                break;
                            }
                            case 4:
                            {
                                grid[i][j].pos = 1;
                                grid[i][j].n = 1;
                                grid[i][j].e = 1;
                                grid[i][j].s = 1;
                                grid[i][j].w = 0;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}

void update_block_textures(Block_t grid[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            switch(grid[i][j].type)
            {
                case 0:
                {
                    grid[i][j].src.x = TILE_SIZE * 2;
                    grid[i][j].src.y = TILE_SIZE;
                    break;
                }
                case 1:
                {
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = 0;
                                    grid[i][j].src.y = 0;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 4;
                                    grid[i][j].src.y = 0;
                                    break;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE;
                                    grid[i][j].src.y = 0;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 5;
                                    grid[i][j].src.y = 0;
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 2;
                                    grid[i][j].src.y = 0;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 6;
                                    grid[i][j].src.y = 0;
                                    break;
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 3;
                                    grid[i][j].src.y = 0;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 7;
                                    grid[i][j].src.y = 0;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = 0;
                                    grid[i][j].src.y = TILE_SIZE;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 4;
                                    grid[i][j].src.y = TILE_SIZE;
                                    break;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE;
                                    grid[i][j].src.y = TILE_SIZE;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 5;
                                    grid[i][j].src.y = TILE_SIZE;
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE;
                                    grid[i][j].src.y = TILE_SIZE;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 5;
                                    grid[i][j].src.y = TILE_SIZE;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
                case 3:
                {
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = 0;
                                    grid[i][j].src.y = TILE_SIZE * 2;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 4;
                                    grid[i][j].src.y = TILE_SIZE * 2;
                                    break;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE;
                                    grid[i][j].src.y = TILE_SIZE * 2;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 5;
                                    grid[i][j].src.y = TILE_SIZE * 2;
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 2;
                                    grid[i][j].src.y = TILE_SIZE * 2;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 6;
                                    grid[i][j].src.y = TILE_SIZE * 2;
                                    break;
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 3;
                                    grid[i][j].src.y = TILE_SIZE * 2;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 7;
                                    grid[i][j].src.y = TILE_SIZE * 2;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
                case 4:
                {
                    switch(grid[i][j].active)
                    {
                        case FALSE:
                        {
                            grid[i][j].src.x = 0;
                            grid[i][j].src.y = TILE_SIZE * 3;
                            break;
                        }
                        case TRUE:
                        {
                            grid[i][j].src.x = TILE_SIZE * 4;
                            grid[i][j].src.y = TILE_SIZE * 3;
                            break;
                        }
                    }
                    break;
                }
                case 5:
                {
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = 0;
                                    grid[i][j].src.y = TILE_SIZE * 4;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 4;
                                    grid[i][j].src.y = TILE_SIZE * 4;
                                    break;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE;
                                    grid[i][j].src.y = TILE_SIZE * 4;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 5;
                                    grid[i][j].src.y = TILE_SIZE * 4;
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 2;
                                    grid[i][j].src.y = TILE_SIZE * 4;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 6;
                                    grid[i][j].src.y = TILE_SIZE * 4;
                                    break;
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 3;
                                    grid[i][j].src.y = TILE_SIZE * 4;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 7;
                                    grid[i][j].src.y = TILE_SIZE * 4;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
                case 6:
                {
                    switch(grid[i][j].pos)
                    {
                        case 1:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = 0;
                                    grid[i][j].src.y = TILE_SIZE * 5;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = 0;
                                    grid[i][j].src.y = TILE_SIZE * 5;
                                    break;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE;
                                    grid[i][j].src.y = TILE_SIZE * 5;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE;
                                    grid[i][j].src.y = TILE_SIZE * 5;
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 2;
                                    grid[i][j].src.y = TILE_SIZE * 5;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 2;
                                    grid[i][j].src.y = TILE_SIZE * 5;
                                    break;
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            switch(grid[i][j].active)
                            {
                                case FALSE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 3;
                                    grid[i][j].src.y = TILE_SIZE * 5;
                                    break;
                                }
                                case TRUE:
                                {
                                    grid[i][j].src.x = TILE_SIZE * 3;
                                    grid[i][j].src.y = TILE_SIZE * 5;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}