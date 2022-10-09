#include "global.h"

// needs to be set first before using get_random_num()
void seed_random_num(void)
{
    srand(time(NULL));
}

int get_random_num(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

int get_cell_x_pos(int cell_index)
{
    return cell_index / ROW_SIZE;
}

int get_cell_y_pos(int cell_index)
{
    return cell_index % COL_SIZE;
}