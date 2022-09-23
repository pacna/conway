#include "colors.h"

uint8_t colors[TOTAL_COLOR_SIZE] = {
    0, 0, 0, 255,       // BLACK
    200, 0, 0, 255,     // RED
    0, 200, 0, 255,     // GREEN
    0, 0, 200, 255,     // BLUE
    255, 255, 255, 255, // WHITE
};

rgba_t get_rgba(color_t color_index)
{
    rgba_t rgba;
    rgba.red = colors[(NUM_OF_RGBA * color_index) + 0];
    rgba.green = colors[(NUM_OF_RGBA * color_index) + 1];
    rgba.blue = colors[(NUM_OF_RGBA * color_index) + 2];
    rgba.alpha = colors[(NUM_OF_RGBA * color_index) + 3];

    return rgba;
}