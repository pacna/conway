#include "global.h"

void render_text(char *text, SDL_Rect message_rect, color_t color)
{
    TTF_Font *open_sans = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 60);

    if (!open_sans)
    {
        log_error_with_added_text("Could not initialize font: ", SDL_GetError());
    }

    SDL_Color sdl_color = get_sdl_rgba(color);
    SDL_Surface *surface_message = TTF_RenderText_Solid(open_sans, text, sdl_color);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_RenderFillRect(renderer, &message_rect);
    SDL_RenderCopy(renderer, message, NULL, &message_rect);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message);

    TTF_CloseFont(open_sans);
}