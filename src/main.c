#include "global.h"

void main(int argc, char *argv[])
{
    if (is_sdl_mode(argv[1]) && init_sdl())
    {
        log_success("Starting Game of Life in SDL mode");
        run_sdl_game_of_life();
    }
    else if (is_terminal_mode(argv[1]))
    {
        log_success("Starting Game of Life in Terminal mode");
        run_terminal_game_of_life();
    }
    else
    {
        log_error("Unable to run app");
    }
}