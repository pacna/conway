#include "global.h"

SDL_Window *window;
SDL_Renderer *renderer;
char *current_mode = NULL;

bool is_sdl_mode(char *input)
{
    return input == NULL || strcmp(SDL_MODE, input) == 0;
}

bool is_terminal_mode(char *input)
{
    return strcmp(TERMINAL_MODE, input) == 0;
}