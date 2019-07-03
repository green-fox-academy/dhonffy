#include "draw.h"

void draw(SDL_Renderer *gRenderer)
{
    // Draw a green 100x100 square to the canvas' center.
    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0xFF /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 270, 190, 270, 290);
    SDL_RenderDrawLine(gRenderer, 270, 190, 370, 190);
    SDL_RenderDrawLine(gRenderer, 370, 190, 370, 290);
    SDL_RenderDrawLine(gRenderer, 370, 290, 270, 290);
}

