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

void render_square()
{
    SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 200;
    rect.h = 200;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void render()
{
    SDL_RenderClear(renderer);

    render_square();

    SDL_RenderPresent(renderer);
}

void run_program()
{
    while (true)
    {
        process_input();
        render();
    }
}

void run_game_of_life()
{
    run_program();
}