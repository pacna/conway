#ifndef GLOBAL__
#define GLOBAL__

// C headers
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

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
#include "draw.h"
#include "terminal_sdl.h"
#include "log.h"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

#define TERMINAL_MODE "terminal"
#define SDL_MODE "sdl"

extern bool is_sdl_mode(char *input);
extern bool is_terminal_mode(char *input);
extern char *current_mode;

#endif