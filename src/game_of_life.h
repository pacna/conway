#ifndef GAME_OF_LIFE__
#define GAME_OF_LIFE__

typedef struct Rect
{
    int x;
    int y;
    int w;
    int h;
    color_t color;
} rect_t;

extern void run_game_of_life();

#endif