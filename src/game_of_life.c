#include "global.h"

void process_input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
            break;
        default:
            break;
        }
    }
}

void run_program()
{
    while (true)
    {
        process_input();
    }
}

void run_game_of_life()
{
    run_program();
}