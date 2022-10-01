#include "global.h"

int random_num(int min, int max)
{
    return min + rand() % (max + 1 - min);
}