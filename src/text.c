#include "global.h"

void render_text(char *text, unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
    TTF_Font *open_sans = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 60);

    if (!open_sans)
    {
        log_error(strcat("Could not initialize font: ", SDL_GetError()));
    }

    SDL_Color sdl_green = get_sdl_rgba(green);

    SDL_Rect message_rect;
    message_rect.x = x;
    message_rect.y = y;
    message_rect.w = w;
    message_rect.h = h;

    SDL_Surface *surface_message = TTF_RenderText_Solid(open_sans, text, sdl_green);

    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_RenderFillRect(renderer, &message_rect);

    SDL_RenderCopy(renderer, message, NULL, &message_rect);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message);

    TTF_CloseFont(open_sans);
}