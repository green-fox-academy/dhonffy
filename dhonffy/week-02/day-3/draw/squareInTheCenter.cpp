#include "draw.h"

void draw(SDL_Renderer *gRenderer)
{
    // Draw a green 100x100 square to the canvas' center.
    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0xFF /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_Rect fillRect = {270, 190, 100, 100};
    SDL_RenderFillRect( gRenderer, &fillRect );
}

