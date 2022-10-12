#include "global.h"

/**
 *  --- Private Functions ---
 **/
static void display_game_text(void)
{
    printf("\n");
    char generation_count_text[16];
    sprintf(generation_count_text, "Generation %d", generation_count);

    printf("%s\n", generation_count_text);
}

static void run_game_of_life(void)
{
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++)
    {
        printf("%d\t", current_generation.cells[i].state);

        if ((i + 1) % ROW_SIZE == 0)
        {
            printf("\n");
        }
    };

    display_game_text();
    set_terminal_timeout(update_generation, 1000);
}

static void run(void)
{
    while (true)
    {
        run_game_of_life();
    }
}

static void run_program(void)
{
    init_game_of_life_setup();
    run();
}

/**
 *  --- Public Functions ---
 **/
void run_terminal_game_of_life(void)
{
    run_program();
}