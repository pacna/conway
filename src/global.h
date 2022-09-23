#ifndef GLOBAL__
#define GLOBAL__

// C headers
#include <stdio.h>
#include <stdbool.h>

// third party headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// project headers
#include "init.h"
#include "colors.h"
#include "game_of_life.h"

#define SUCCESS 1
#define FAIL 0

extern SDL_Window* window;
extern SDL_Renderer* renderer;

#endif