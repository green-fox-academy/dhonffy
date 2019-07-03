#include "draw.h"

void draw(SDL_Renderer* gRenderer)
{
    // draw a red horizontal line to the canvas' middle.
    //choose color
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    //draw line
    SDL_RenderDrawLine(gRenderer, 0, 240, 640, 240);
    // draw a green vertical line to the canvas' middle.
    //choose color
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    //draw line
    SDL_RenderDrawLine(gRenderer, 320, 0, 320, 480);

}