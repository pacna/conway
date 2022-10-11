#include "global.h"

grid_t current_generation, next_generation;
unsigned int generation_count = 0;

/**
 *  --- Private Functions ---
 **/
static bool is_in_range(int current_index)
{
    return current_index >= 0 && current_index < GRID_SIZE;
}

static bool is_valid_pos(int pos)
{
    return pos >= 0 && pos < ROW_SIZE;
}

static int find_index(int neighbor_x_pos, int neighbor_y_pos)
{
    return COL_SIZE * neighbor_x_pos + neighbor_y_pos;
}

static bool is_cell_alive(grid_t *grid, int neighbor_x_pos, int neighbor_y_pos)
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

static void update_cell(unsigned int alive_count, unsigned int cell, int current_index)
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

static void init_generation(void)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        current_generation.cells[i].state = get_random_num(0, 1);
    }

    next_generation = current_generation;
}

static void update_current_generation(void)
{
    current_generation = next_generation;
}

static void figure_out_alive_cells(void)
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

/**
 *  --- Public Functions ---
 **/

void init_game_of_life_setup(void)
{
    seed_random_num();
    init_generation();
}

void update_generation(void)
{
    figure_out_alive_cells();
    generation_count++;
}