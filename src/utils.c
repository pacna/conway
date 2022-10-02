#include "global.h"

int random_num(int min, int max)
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