#include "global.h"

int init_SDL(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        log_error(strcat("Could not intialize SDL: ", SDL_GetError()));
        return 0;
    }

    return 1;
}

int init_window(void)
{
    window = NULL;

    if (!init_SDL())
    {
        return 0;
    }

    window = SDL_CreateWindow(
        "SDL Game of Life",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        log_error(strcat("Could not intialize window: ", SDL_GetError()));
        return 0;
    }

    return 1;
}

int init_renderer(void)
{
    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        log_error(strcat("Could not intialize renderer: ", SDL_GetError()));
        return -1;
    }

    return 1;
}

int init_TTF(void)
{
    if (TTF_Init() == -1)
    {
        log_error(strcat("Could not intialize TTF: ", SDL_GetError()));
        return -1;
    }

    return 1;
}

int init_sdl(void)
{
    if (!init_window())
    {
        return 0;
    }

    if (!init_renderer())
    {
        return 0;
    }

    if (!init_TTF())
    {
        return 0;
    }

    return 1;
}
