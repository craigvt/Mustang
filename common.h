#ifndef COMMON_H
#define COMMON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NATIVE_W 1440
#define NATIVE_H 2560
#define WINDOW_W 768
#define WINDOW_H 1024
#define WINDOW_X 200
#define WINDOW_Y 200
#define TILE_SIZE 240
#define ROWS 9
#define COLS 6
#define INPUT_TYPE SDL_MOUSEBUTTONDOWN

#ifdef __ANDROID__
    #include <android/log.h> 
    #define LOG_TAG "alog"
    #define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
    #define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#endif

#endif /* COMMON_H */