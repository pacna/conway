#include "main.h"

#define EXIT 0

int main()
{
    if (init_game_of_life())
    {
        run_game_of_life();
    }

    return EXIT;
}