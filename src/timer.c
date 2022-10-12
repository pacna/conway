#include "global.h"

static int last_time = 0;
static int current_time;

void set_sdl_timeout(void (*fn)(void), int ms)
{
    current_time = SDL_GetTicks();
    if (current_time > last_time + ms)
    {
        (fn());
        last_time = current_time;
    }
}

void set_terminal_timeout(void (*fn)(void), int ms)
{
    sleep(ms / 1000);
    (fn());
}