#ifndef SYSTEM_H
#define SYSTEM_H

#include "common.h"
#include "data.h"

void init_sdl(SDL_t *sdl);
void get_platform(SDL_t *sdl);
void set_scale(SDL_t *sdl);

#endif /* SYSTEM_H */