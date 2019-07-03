#include "draw.h"

void draw(SDL_Renderer* gRenderer)
{
    // Draw a box that has different colored lines on each edge.
    // The center of the box should align with the center of the screen.
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 120, 200, 480, 200);
    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0xFF /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 480, 200, 480, 280);
    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0xFF /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 120, 280, 480, 280);
    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0xFF /*G*/, 0xFF /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, 120, 200, 120, 280);
}
