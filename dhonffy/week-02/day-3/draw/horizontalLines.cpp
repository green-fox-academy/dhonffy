#include "draw.h"

void center(SDL_Renderer*, int, int);

void draw(SDL_Renderer *gRenderer)
{
    // Create a function that draws a single line and takes 2 parameters:
    // The x and y coordinates of the line's starting point
    // and draws a 50 long horizontal line from that point.
    // Draw at least 3 lines with that function using a loop.
    int x1 = 100;
    int y1 = 130;
    center(gRenderer, x1, y1);
}

void center(SDL_Renderer *gRenderer, int x1, int y1)
{
    for (int i = 0; i < 23; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, x1, y1 + 5 * i, x1 + 50, y1 + 5 * i);
    }
}
