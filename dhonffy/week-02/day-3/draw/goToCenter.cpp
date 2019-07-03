#include "draw.h"

void center(SDL_Renderer*, int, int);

void draw(SDL_Renderer *gRenderer)
{
    // Create a function that draws a single line and takes 2 parameters:
    // The x and y coordinates of the line's starting point
    // and draws a line from that point to the center of the canvas.
    // Draw at least 3 lines with that function using a loop.
    int x1 = 400;
    int y1 = 410;
    center(gRenderer, x1, y1);
}

void center(SDL_Renderer *gRenderer, int x1, int y1)
{
    for (int i = 0; i < 23; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0xFF /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, x1 - 10 *i, y1 - 10 *i, 320, 240);
    }
}
