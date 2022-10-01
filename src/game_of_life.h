#ifndef GAME_OF_LIFE__
#define GAME_OF_LIFE__

#define ROW_SIZE 12
#define COL_SIZE 12
#define GRID_SIZE (ROW_SIZE * COL_SIZE)

#define GRID_X_PADDING 5
#define GRID_Y_PADDING 5
#define CELL_SIZE 20
#define CELL_PADDING 10

#define START_X(x) (GRID_X_PADDING + CELL_PADDING + ((x)*CELL_SIZE))
#define START_Y(y) (GRID_Y_PADDING + CELL_PADDING + ((y)*CELL_SIZE))

typedef struct Cell
{
    unsigned int state; // only two states. 1 - Alive or 0 - Dead
} cell_t;

typedef struct Grid
{
    cell_t cells[GRID_SIZE];
} grid_t;

extern void run_game_of_life();

#endif