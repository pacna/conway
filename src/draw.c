#include "global.h"

void create_rect(SDL_Rect rect, color_t color)
{
    rgba_t sdl_rect_rgba = get_rgba(color);

    SDL_SetRenderDrawColor(renderer, sdl_rect_rgba.red, sdl_rect_rgba.green, sdl_rect_rgba.blue, sdl_rect_rgba.alpha);
    SDL_RenderDrawRect(renderer, &rect);
}

void create_fill_rect(SDL_Rect rect, color_t color)
{
    rgba_t sdl_rect_rgba = get_rgba(color);

    SDL_SetRenderDrawColor(renderer, sdl_rect_rgba.red, sdl_rect_rgba.green, sdl_rect_rgba.blue, sdl_rect_rgba.alpha);
    SDL_RenderFillRect(renderer, &rect);
}