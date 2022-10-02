#include "global.h"

grid_t current_generation, next_generation;

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

void render_square(int x, int y, int is_alive)
{
    SDL_Rect rect;
    rect.x = NEXT_X(x);
    rect.y = NEXT_Y(y);
    rect.w = CELL_SIZE;
    rect.h = CELL_SIZE;

    if (is_alive)
    {
        create_fill_rect(rect, green);
    }
    else
    {
        create_rect(rect, green);
    }
}

void init_generation()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        current_generation.cells[i].state = random_num(0, 1);
    }
}

void render_game_of_life()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        render_square(get_cell_x_pos(i), get_cell_y_pos(i), current_generation.cells[i].state);
    }
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
    render_game_of_life();
    SDL_RenderPresent(renderer);
}

void run_program()
{
    init_generation();

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