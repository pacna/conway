#ifndef GLOBAL__
#define GLOBAL__

// C headers
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Third party headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Project headers
#include "init.h"
#include "colors.h"
#include "game_of_life.h"
#include "utils.h"
#include "text.h"
#include "timer.h"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

#endif