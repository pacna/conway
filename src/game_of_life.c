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

void create_rect(rect_t rect)
{
    SDL_Rect sdl_rect;
    sdl_rect.x = rect.x;
    sdl_rect.y = rect.y;
    sdl_rect.w = rect.w;
    sdl_rect.h = rect.h;

    rgba_t sdl_rect_rgba = get_rgba(rect.color);

    SDL_SetRenderDrawColor(renderer, sdl_rect_rgba.red, sdl_rect_rgba.green, sdl_rect_rgba.blue, sdl_rect_rgba.alpha);
    SDL_RenderDrawRect(renderer, &sdl_rect);
}

void create_fill_rect(rect_t rect)
{
    SDL_Rect sdl_rect;
    sdl_rect.x = rect.x;
    sdl_rect.y = rect.y;
    sdl_rect.w = rect.w;
    sdl_rect.h = rect.h;

    rgba_t sdl_rect_rgba = get_rgba(rect.color);

    SDL_SetRenderDrawColor(renderer, sdl_rect_rgba.red, sdl_rect_rgba.green, sdl_rect_rgba.blue, sdl_rect_rgba.alpha);
    SDL_RenderFillRect(renderer, &sdl_rect);
}

void render_square()
{
    rect_t rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 20;
    rect.h = 20;
    rect.color = red;
    create_rect(rect);
}

void render_background()
{
    rgba_t background_rgba = get_rgba(black);
    SDL_SetRenderDrawColor(renderer, background_rgba.red, background_rgba.green, background_rgba.blue, background_rgba.alpha);
}

void render()
{
    render_background();
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