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

static void render_cell(unsigned int x, unsigned int y, int is_alive)
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

static void render_game_text(void)
{
    char generation_count_text[18];
    sprintf(generation_count_text, "Next Generation %d", generation_count);

    render_text("Game of Life", WINDOW_WIDTH / 3, 0, 250, GRID_Y_PADDING);
    render_text(generation_count_text, WINDOW_WIDTH / 4, WINDOW_HEIGHT - GRID_Y_PADDING, 350, GRID_Y_PADDING);
}

static void render_game_of_life(void)
{
    render_game_text();

    for (int i = 0; i < GRID_SIZE; i++)
    {
        render_cell(get_cell_x_pos(i), get_cell_y_pos(i), current_generation.cells[i].state);
    }

    timer_lock(&update_generation, 1000);
}

static void render_background(void)
{
    rgba_t background_rgba = get_rgba(black);
    SDL_SetRenderDrawColor(renderer, background_rgba.red, background_rgba.green, background_rgba.blue, background_rgba.alpha);
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