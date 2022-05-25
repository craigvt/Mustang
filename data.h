#ifndef DATA_H
#define DATA_H

#include "common.h"

typedef enum {
    FALSE,
    TRUE
} Boolean_t;

typedef enum {
    INTRO,
    START,
    PLAY,
    LEVEL_WON,
    MENU
} State_t;

typedef struct {
    int platform;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int device_w, device_h;
    int render_w, render_h;
    int offset_w, offset_h;
    float scale_factor;
} SDL_t;

typedef struct {
    SDL_Texture *atlas;
    SDL_Texture *background;
    SDL_Texture *bgTarget;
    SDL_Texture *stageTarget;
    SDL_Rect bgTarget_dst;
    SDL_Rect stageTarget_dst;
} Render_t;

typedef struct {
    SDL_Rect intro_logo_src;
    SDL_Rect intro_logo_dst;
    SDL_Rect start_logo_src;
    SDL_Rect start_logo_dst;
    SDL_Rect start_btn_src;
    SDL_Rect start_btn_dst;
} Start_t;

typedef struct {
    int current_level;
    int key_block;
    int power_blocks;
    Boolean_t running;
    State_t state;
    Boolean_t reset_level;
    Boolean_t block_touched;
} Game_t;

typedef struct {
    int id;
    int type;
    int pos;
    int n, e, s, w;
    Boolean_t active;
    Boolean_t in_path_que;
    Boolean_t first_block;
    SDL_Rect src;
    SDL_Rect dst;
} Block_t;

typedef struct {
    SDL_Rect display_src;
    SDL_Rect display_dst;
    SDL_Rect options_src;
    SDL_Rect options_dst;
    SDL_Rect notice_src;
    SDL_Rect notice_dst;

    SDL_Rect menu_src;
    SDL_Rect menu_dst;
    SDL_Rect menu_close_dst;
} UI_t;

typedef struct {
    int input_loc;
    int input_x, input_y;
    SDL_Event event;
} Input_t;

#endif /* DATA_H */