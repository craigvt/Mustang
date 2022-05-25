#include "system.h"

void init_sdl(SDL_t *sdl)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    get_platform(sdl);

    switch(sdl->platform)
    {
        case 1: // Linux
        {
            sdl->window = SDL_CreateWindow("Mustang Engine", WINDOW_X, WINDOW_Y, WINDOW_W, WINDOW_H, SDL_WINDOW_OPENGL);
            sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
            break;
        }
        case 2: // Android
        {
            sdl->window = SDL_CreateWindow("Mustang Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, NATIVE_W, NATIVE_H, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
            sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
            break;
        }
    }

    set_scale(sdl);
}

void get_platform(SDL_t *sdl)
{
    const char Linux[] = "Linux";
    const char Android[] = "Android";
    const char *os;
    os = SDL_GetPlatform();

    if(strcmp(os, Linux) == 0)
    {
        sdl->platform = 1;
    }
    if(strcmp(os, Android) == 0)
    {
        sdl->platform = 2;
    }
}

void set_scale(SDL_t *sdl) 
{
    SDL_GetRendererOutputSize(sdl->renderer, &sdl->device_w, &sdl->device_h);
    sdl->scale_factor = (float)sdl->device_h / NATIVE_H;
    sdl->render_w = NATIVE_W * sdl->scale_factor;
    sdl->render_h = NATIVE_H * sdl->scale_factor;
    sdl->offset_w = (sdl->device_w - sdl->render_w) / 2;
    sdl->offset_h = (sdl->device_h - sdl->render_h) / 2;
    printf("Device W: %d, Device H: %d \n", sdl->device_w, sdl->device_h);
    printf("Render W: %d, Device H: %d \n", sdl->render_w, sdl->render_h);
    printf("Scale Offset W: %d, Scale Offset H: %d \n", sdl->offset_w, sdl->offset_h);
}