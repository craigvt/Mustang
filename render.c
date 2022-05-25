#include "render.h"

void init_render(SDL_t *sdl, Render_t *render)
{
    render->atlas = IMG_LoadTexture(sdl->renderer, "assets/atlas.png");
    render->background = IMG_LoadTexture(sdl->renderer, "assets/background.png");

    render->bgTarget = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, NATIVE_W, NATIVE_H);
    render->bgTarget_dst.x = 0;
    render->bgTarget_dst.y = 0;
    render->bgTarget_dst.w = sdl->device_w;
    render->bgTarget_dst.h = sdl->device_h;

    render->stageTarget = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, NATIVE_W, NATIVE_H);
    SDL_SetTextureBlendMode(render->stageTarget, SDL_BLENDMODE_BLEND);
    render->stageTarget_dst.x = sdl->offset_w;
    render->stageTarget_dst.y = sdl->offset_h;
    render->stageTarget_dst.w = sdl->render_w;
    render->stageTarget_dst.h = sdl->render_h;
}

void MAIN_render(SDL_t *sdl, Render_t *render, Game_t *game, Start_t *start, Input_t *input, UI_t *ui, Block_t grid[ROWS][COLS])
{
    // render to BG target
    SDL_SetRenderTarget(sdl->renderer, render->bgTarget);
    SDL_RenderCopy(sdl->renderer, render->background, NULL, NULL);
    
    // render to stage target
    SDL_SetRenderTarget(sdl->renderer, render->stageTarget);

    switch(game->state)
    {
        case INTRO:
        {
            render_intro(sdl, render, start);
            break;
        }
        case START:
        {
            render_start(sdl, render, start);
            break;
        }
        case PLAY:
        {
            render_grid(sdl, render, grid);
            render_ui(sdl, render, game, ui);
            break;
        }
        case MENU:
        {
            render_grid(sdl, render, grid);
            render_ui(sdl, render, game, ui);
            render_menu(sdl, render, ui);
            break;
        }
        case LEVEL_WON:
        {
            render_grid(sdl, render, grid);
            render_ui(sdl, render, game, ui);
            render_notice(sdl, render, ui);
            break;
        }
    }

    // render targets to window
    SDL_SetRenderTarget(sdl->renderer, NULL);
    SDL_RenderCopy(sdl->renderer, render->bgTarget, NULL, NULL);
    SDL_RenderCopy(sdl->renderer, render->stageTarget, NULL, &render->stageTarget_dst);

    // present renderer
    SDL_RenderPresent(sdl->renderer);
}

void render_intro(SDL_t *sdl, Render_t *render, Start_t *start)
{
    SDL_RenderCopy(sdl->renderer, render->atlas, &start->intro_logo_src, &start->intro_logo_dst);
}

void render_start(SDL_t *sdl, Render_t *render, Start_t *start)
{
    SDL_RenderCopy(sdl->renderer, render->atlas, &start->start_logo_src, &start->start_logo_dst);
    SDL_RenderCopy(sdl->renderer, render->atlas, &start->start_btn_src, &start->start_btn_dst);
}

void render_ui(SDL_t *sdl, Render_t *render, Game_t *game, UI_t *ui)
{
    SDL_RenderCopy(sdl->renderer, render->atlas, &ui->display_src, &ui->display_dst);
    SDL_RenderCopy(sdl->renderer, render->atlas, &ui->options_src, &ui->options_dst);
}

void render_menu(SDL_t *sdl, Render_t *render, UI_t *ui)
{
    SDL_RenderCopy(sdl->renderer, render->atlas, &ui->menu_src, &ui->menu_dst);
}

void render_notice(SDL_t *sdl, Render_t *render, UI_t *ui)
{
    SDL_RenderCopy(sdl->renderer, render->atlas, &ui->notice_src, &ui->notice_dst);
}

void render_grid(SDL_t *sdl, Render_t *render, Block_t grid[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            SDL_RenderCopy(sdl->renderer, render->atlas, &grid[i][j].src, &grid[i][j].dst);
        }
    }
}