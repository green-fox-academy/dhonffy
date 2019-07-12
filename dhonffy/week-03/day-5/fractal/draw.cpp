#include "draw.h"

void draw(SDL_Renderer* gRenderer)
{
//choose color
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
//draw line
    SDL_RenderDrawLine(gRenderer, 0, 0, 200, 200);
}