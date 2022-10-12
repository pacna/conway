#include "global.h"

void create_rect(SDL_Rect rect, color_t color)
{
    SDL_Color sdl_rect_rgba = get_sdl_rgba(color);

    SDL_SetRenderDrawColor(renderer, sdl_rect_rgba.r, sdl_rect_rgba.g, sdl_rect_rgba.b, sdl_rect_rgba.a);
    SDL_RenderDrawRect(renderer, &rect);
}

void create_fill_rect(SDL_Rect rect, color_t color)
{
    SDL_Color sdl_rect_rgba = get_sdl_rgba(color);

    SDL_SetRenderDrawColor(renderer, sdl_rect_rgba.r, sdl_rect_rgba.g, sdl_rect_rgba.b, sdl_rect_rgba.a);
    SDL_RenderFillRect(renderer, &rect);
}