#ifndef GAME_OF_LIFE__
#define GAME_OF_LIFE__

#define ROW_SIZE 15
#define COL_SIZE 15
#define GRID_SIZE (ROW_SIZE * COL_SIZE)

#define GRID_X_PADDING 50
#define GRID_Y_PADDING 90
#define CELL_SIZE 40

#define NEXT_X(x) (GRID_X_PADDING + ((x)*CELL_SIZE))
#define NEXT_Y(y) (GRID_Y_PADDING + ((y)*CELL_SIZE))

typedef enum Cell_State
{
    dead,
    alive
} cell_state_t;

typedef struct Cell
{
    cell_state_t state;
} cell_t;

typedef struct Grid
{
    cell_t cells[GRID_SIZE];
} grid_t;

extern void run_sdl_game_of_life(void);

#endif