#include "global.h"

grid_t current_generation, next_generation;

unsigned int generation_count = 0;

void render_cell(unsigned int x, unsigned int y, int is_alive)
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

bool is_in_range(int current_index)
{
    return current_index >= 0 && current_index < GRID_SIZE;
}

bool is_valid_pos(int pos)
{
    return pos >= 0 && pos < ROW_SIZE;
}

int find_index(int neighbor_x_pos, int neighbor_y_pos)
{
    return COL_SIZE * neighbor_x_pos + neighbor_y_pos;
}

bool is_cell_alive(grid_t *grid, int neighbor_x_pos, int neighbor_y_pos)
{
    if (is_valid_pos(neighbor_x_pos) && is_valid_pos(neighbor_y_pos))
    {
        int index = find_index(neighbor_x_pos, neighbor_y_pos);

        if (is_in_range(index))
        {
            return grid->cells[index].state == alive;
        }

        return false;
    }

    return false;
}

void update_current_generation(void)
{
    current_generation = next_generation;
}

void update_cell(unsigned int alive_count, unsigned int cell, int current_index)
{
    if (cell == alive)
    {
        if (alive_count == 2 || alive_count == 3)
        {
            next_generation.cells[current_index].state = alive;
        }
        else
        {
            next_generation.cells[current_index].state = dead;
        }
    }
    else
    {
        if (alive_count == 3)
        { // only way a dead cell can be revived if it has exactly 3 alive neighbors
            next_generation.cells[current_index].state = alive;
        }
        else
        {
            next_generation.cells[current_index].state = dead;
        }
    }
}

void figure_out_alive_cells(void)
{
    unsigned int alive_count = 0;
    // neighbors: LEFT, RIGHT, TOP, DOWN, TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT
    int neighbor_x_offset[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int neighbor_y_offset[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int n = 0; n < GRID_SIZE; n++)
    {
        int neighbor_x, neighbor_y;

        for (int i = 0; i < 8; i++)
        {
            neighbor_x = get_cell_x_pos(n) + neighbor_x_offset[i];
            neighbor_y = get_cell_y_pos(n) + neighbor_y_offset[i];

            if (is_cell_alive(&current_generation, neighbor_x, neighbor_y))
            {
                alive_count++;
            }
        }

        update_cell(alive_count, current_generation.cells[n].state, n);
        alive_count = 0;
    }

    update_current_generation();
}

void init_generation(void)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        current_generation.cells[i].state = get_random_num(0, 1);
    }

    next_generation = current_generation;
}

void render_game_text(void)
{
    char generation_count_text[18];
    sprintf(generation_count_text, "Next Generation %d", generation_count);

    render_text("Game of Life", WINDOW_WIDTH / 3, 0, 250, GRID_Y_PADDING);
    render_text(generation_count_text, WINDOW_WIDTH / 4, WINDOW_HEIGHT - GRID_Y_PADDING, 350, GRID_Y_PADDING);
}

void update_generation(void)
{
    figure_out_alive_cells();
    generation_count++;
}

void render_game_of_life(void)
{
    render_game_text();

    for (int i = 0; i < GRID_SIZE; i++)
    {
        render_cell(get_cell_x_pos(i), get_cell_y_pos(i), current_generation.cells[i].state);
    }

    timer_lock(&update_generation, 1000);
}

void render_background(void)
{
    rgba_t background_rgba = get_rgba(black);
    SDL_SetRenderDrawColor(renderer, background_rgba.red, background_rgba.green, background_rgba.blue, background_rgba.alpha);
}

void render(void)
{
    render_background();
    SDL_RenderClear(renderer);
    render_game_of_life();
    SDL_RenderPresent(renderer);
}

void run_program(void)
{
    seed_random_num();
    init_generation();

    while (true)
    {
        process_input();
        render();
    }
}

void run_sdl_game_of_life(void)
{
    run_program();
}