#include "ui.h"

void init_ui(UI_t *ui)
{
    // display
    ui->display_dst.x = TILE_SIZE;
    ui->display_dst.y = 0;
    ui->display_dst.w = TILE_SIZE * 4;
    ui->display_dst.h = TILE_SIZE;

    ui->display_src.x = 0;
    ui->display_src.y = TILE_SIZE * 6;
    ui->display_src.w = TILE_SIZE * 4;
    ui->display_src.h = TILE_SIZE;

    // options
    ui->options_dst.x = TILE_SIZE * 5;
    ui->options_dst.y = 0;
    ui->options_dst.w = TILE_SIZE;
    ui->options_dst.h = TILE_SIZE;

    ui->options_src.x = 0;
    ui->options_src.y = TILE_SIZE * 7;
    ui->options_src.w = TILE_SIZE;
    ui->options_src.h = TILE_SIZE;

    // level won notice
    ui->notice_dst.x = TILE_SIZE;
    ui->notice_dst.y = TILE_SIZE * 3;
    ui->notice_dst.w = TILE_SIZE * 4;
    ui->notice_dst.h = TILE_SIZE * 3;

    ui->notice_src.x = 0;
    ui->notice_src.y = TILE_SIZE * 8;
    ui->notice_src.w = TILE_SIZE * 4;
    ui->notice_src.h = TILE_SIZE * 3;

    // options menu
    ui->menu_dst.x = TILE_SIZE;
    ui->menu_dst.y = TILE_SIZE * 2;
    ui->menu_dst.w = TILE_SIZE * 4;
    ui->menu_dst.h = TILE_SIZE * 6;

    ui->menu_src.x = TILE_SIZE * 4;
    ui->menu_src.y = TILE_SIZE * 5;
    ui->menu_src.w = TILE_SIZE * 4;
    ui->menu_src.h = TILE_SIZE * 6;

    // options menu close
    ui->menu_close_dst.x = TILE_SIZE * 4;
    ui->menu_close_dst.y = TILE_SIZE * 2;
    ui->menu_close_dst.w = TILE_SIZE;
    ui->menu_close_dst.h = TILE_SIZE;
}