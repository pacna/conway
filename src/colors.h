#ifndef COLORS__
#define COLORS__

#include <stdint.h>

#define NUM_OF_RGBA 4
#define NUM_OF_COLOR_OPTIONS 5
#define TOTAL_COLOR_SIZE NUM_OF_RGBA *NUM_OF_COLOR_OPTIONS

typedef enum Color
{
    black,
    red,
    green,
    blue,
    white
} color_t;

typedef struct RGBA
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} rgba_t;

extern uint8_t color_values[TOTAL_COLOR_SIZE];
extern rgba_t get_rgba(color_t color_index);
extern SDL_Color get_sdl_rgba(color_t color_index);

#endif