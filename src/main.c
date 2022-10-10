#include "global.h"

void main(int argc, char *argv[])
{
    if (is_sdl_mode(argv[1]) && init_sdl())
    {
        current_mode = SDL_MODE;
        log_success("Starting Game of Life in SDL mode");
        run_sdl_game_of_life();
    }
    else if (is_terminal_mode(argv[1]))
    {
        current_mode = TERMINAL_MODE;
        log_success("Starting Game of Life in Terminal mode");
        run_terminal_game_of_life();
    }
    else
    {
        log_error("Invalid input");
    }
}