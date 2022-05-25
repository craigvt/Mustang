#include "input.h"

void MAIN_input(SDL_t *sdl, Render_t *render, Game_t *game, Start_t *start, Input_t *input, UI_t *ui, Block_t grid[ROWS][COLS])
{
    Boolean_t touch_event = FALSE;

    float x_dif = (float)NATIVE_W / (float)sdl->device_w;
    float y_dif = (float)NATIVE_H / (float)sdl->device_h;

    // proccess event
    switch(input->event.type)
    {
        case SDL_QUIT:
        {
            game->running = FALSE;
            break;
        }
        case INPUT_TYPE:
        {
            input->input_x = input->event.button.x * x_dif;
            input->input_y = input->event.button.y * y_dif;
            touch_event = TRUE;

            break;
        }
    }

    // proccess input location
    if(touch_event)
    {
        switch(game->state)
        {
            case INTRO:
            {
                game->state = START;
                break;
            }
            case START:
            {
                if((input->input_x > start->start_btn_dst.x) && (input->input_x < start->start_btn_dst.x + start->start_btn_dst.w) &&
                    (input->input_y > start->start_btn_dst.y) && (input->input_y < start->start_btn_dst.y + start->start_btn_dst.h))
                {
                    game->state = PLAY;
                }
                break;
            }
            case PLAY:
            {
                // options menu touch
                if((input->input_x > ui->options_dst.x) && (input->input_x < ui->options_dst.x + ui->options_dst.w) &&
                    (input->input_y > ui->options_dst.y) && (input->input_y < ui->options_dst.y + ui->options_dst.h))
                {
                    game->state = MENU;
                }
                // block touch
                for(int i = 0; i < ROWS; i++)
                {
                    for(int j = 0; j < COLS; j++)
                    {
                        // check for block touch
                        if((input->input_x > grid[i][j].dst.x) && (input->input_x < grid[i][j].dst.x + TILE_SIZE ) &&
                            (input->input_y > grid[i][j].dst.y) && (input->input_y < grid[i][j].dst.y + TILE_SIZE ))
                        {
                            input->input_loc = grid[i][j].id;
                            
                            game->block_touched = TRUE;                  
                        }
                    }
                }
                break;
            }
            case MENU:
            {
                // menu close
                if((input->input_x > ui->menu_close_dst.x) && (input->input_x < ui->menu_close_dst.x + ui->menu_close_dst.w) &&
                    (input->input_y > ui->menu_close_dst.y) && (input->input_y < ui->menu_close_dst.y + ui->menu_close_dst.h))
                {
                    game->state = PLAY;
                }
                break;
            }
            case LEVEL_WON:
            {
                // notice touch
                if((input->input_x > ui->notice_dst.x) && (input->input_x < ui->notice_dst.x + ui->notice_dst.w) &&
                    (input->input_y > ui->notice_dst.y) && (input->input_y < ui->notice_dst.y + ui->notice_dst.h))
                {
                    game->reset_level = TRUE;
                }
            }
        }
    }
}