#include "global.h"

/**
 *  --- Private Functions ---
 **/
static void process_input(void)
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

static void render_cell(int x, int y, int is_alive, color_t color)
{
    SDL_Rect rect;
    rect.x = NEXT_X(x);
    rect.y = NEXT_Y(y);
    rect.w = CELL_SIZE;
    rect.h = CELL_SIZE;

    if (is_alive)
    {
        create_fill_rect(rect, color);
    }
    else
    {
        create_rect(rect, color);
    }
}

static void render_game_text(void)
{
    char generation_count_text[16];
    sprintf(generation_count_text, "Generation %d", generation_count);

    SDL_Rect title_rect;
    title_rect.x = WINDOW_WIDTH / 3;
    title_rect.y = 0;
    title_rect.w = 250;
    title_rect.h = GRID_X_PADDING;

    SDL_Rect generation_rect;
    generation_rect.x = WINDOW_WIDTH / 4;
    generation_rect.y = WINDOW_HEIGHT - GRID_Y_PADDING;
    generation_rect.w = 350;
    generation_rect.h = GRID_Y_PADDING;

    render_text("Game of Life", title_rect, green);
    render_text(generation_count_text, generation_rect, green);
}

static void render_game_of_life(void)
{
    render_game_text();

    for (int i = 0; i < GRID_SIZE; i++)
    {
        render_cell(get_cell_x_pos(i), get_cell_y_pos(i), current_generation.cells[i].state, green);
    }

    set_sdl_timeout(&update_generation, 1000);
}

static void render_background(void)
{
    SDL_Color background_rgba = get_sdl_rgba(black);
    SDL_SetRenderDrawColor(renderer, background_rgba.r, background_rgba.g, background_rgba.b, background_rgba.a);
}

static void render(void)
{
    render_background();
    SDL_RenderClear(renderer);
    render_game_of_life();
    SDL_RenderPresent(renderer);
}

static void run_program(void)
{
    init_game_of_life_setup();

    while (true)
    {
        process_input();
        render();
    }
}

/**
 *  --- Public Functions ---
 **/
void run_sdl_game_of_life(void)
{
    run_program();
}