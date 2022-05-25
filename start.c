#include "start.h"

void init_start(Start_t *start)
{
    // intro logo
    start->intro_logo_dst.x = TILE_SIZE;
    start->intro_logo_dst.y = TILE_SIZE * 3;
    start->intro_logo_dst.w = TILE_SIZE * 4;
    start->intro_logo_dst.h = TILE_SIZE * 3;

    start->intro_logo_src.x = 0;
    start->intro_logo_src.y = TILE_SIZE * 12;
    start->intro_logo_src.w = TILE_SIZE * 4;
    start->intro_logo_src.h = TILE_SIZE * 3;

    // start logo
    start->start_logo_dst.x = TILE_SIZE;
    start->start_logo_dst.y = TILE_SIZE * 2;
    start->start_logo_dst.w = TILE_SIZE * 4;
    start->start_logo_dst.h = TILE_SIZE * 3;

    start->start_logo_src.x = TILE_SIZE * 4;
    start->start_logo_src.y = TILE_SIZE * 11;
    start->start_logo_src.w = TILE_SIZE * 4;
    start->start_logo_src.h = TILE_SIZE * 3;

    // start button
    start->start_btn_dst.x = TILE_SIZE;
    start->start_btn_dst.y = TILE_SIZE * 6;
    start->start_btn_dst.w = TILE_SIZE * 4;
    start->start_btn_dst.h = TILE_SIZE;

    start->start_btn_src.x = TILE_SIZE * 4;
    start->start_btn_src.y = TILE_SIZE * 14;
    start->start_btn_src.w = TILE_SIZE * 4;
    start->start_btn_src.h = TILE_SIZE;
}