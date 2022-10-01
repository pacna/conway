#ifndef GLOBAL__
#define GLOBAL__

// C headers
#include <stdio.h>
#include <stdbool.h>

// Third party headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Project headers
#include "init.h"
#include "colors.h"
#include "game_of_life.h"
#include "utils.h"

#define SUCCESS 1
#define FAIL 0

extern SDL_Window *window;
extern SDL_Renderer *renderer;

#endif