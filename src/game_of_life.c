#include "global.h"

grid_t grid, next_generation_grid;

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

void create_rect(SDL_Rect rect, color_t color)
{
    rgba_t sdl_rect_rgba = get_rgba(color);

    SDL_SetRenderDrawColor(renderer, sdl_rect_rgba.red, sdl_rect_rgba.green, sdl_rect_rgba.blue, sdl_rect_rgba.alpha);
    SDL_RenderDrawRect(renderer, &rect);
}

void create_fill_rect(SDL_Rect rect, color_t color)
{
    rgba_t sdl_rect_rgba = get_rgba(color);

    SDL_SetRenderDrawColor(renderer, sdl_rect_rgba.red, sdl_rect_rgba.green, sdl_rect_rgba.blue, sdl_rect_rgba.alpha);
    SDL_RenderFillRect(renderer, &rect);
}

void render_square()
{
    SDL_Rect rect;
    rect.x = START_X(0);
    rect.y = START_Y(0);
    rect.w = CELL_SIZE;
    rect.h = CELL_SIZE;
    create_rect(rect, green);
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