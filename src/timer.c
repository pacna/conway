#include "global.h"

unsigned int last_time = 0, current_time;

void timer_lock(void (*fn)(void), unsigned int ms)
{
    current_time = SDL_GetTicks();
    if (current_time > last_time + ms)
    {
        (fn());
        last_time = current_time;
    }
}