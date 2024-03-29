#include "draw.h"

void drawBox(SDL_Renderer *, int);

void draw(SDL_Renderer *gRenderer)
{
    // create a function that draws one square and takes 1 parameters:
    // the square size
    // and draws a square of that size to the center of the canvas.
    // draw at least 3 squares with that function.
    // the squares should not be filled otherwise they will hide each other
    // avoid code duplication.
    int size1 = 40;
    drawBox(gRenderer, size1);
    int size2 = 100;
    drawBox(gRenderer, size2);
    int size3 = 200;
    drawBox(gRenderer, size3);
}

void drawBox(SDL_Renderer *gRenderer, int size)
{
    int halfSize = size / 2;
    SDL_SetRenderDrawColor(gRenderer, 0x20 /*R*/, 0x10 /*G*/, 0xA0 /*B*/, 0x00 /*A*/);
    SDL_Rect fillRect = {320 - halfSize, 240 - halfSize, size, size};
    SDL_RenderDrawRect(gRenderer, &fillRect);
}
