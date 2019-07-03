#include "draw.h"

void drawSquare(SDL_Renderer *, int, int);

void draw(SDL_Renderer *gRenderer)
{
    // create a function that draws one square and takes 2 parameters:
    // the x and y coordinates of the square's top left corner
    // and draws a 50x50 square from that point.
    // draw at least 3 squares with that function.
    // avoid code duplication.
    int x1 = 50;
    int y1 = 50;
    drawSquare(gRenderer, x1, y1);
    int x2 = 110;
    int y2 = 150;
    drawSquare(gRenderer, x2, y2);
    int x3 = 350;
    int y3 = 250;
    drawSquare(gRenderer, x3, y3);
}

void drawSquare(SDL_Renderer *gRenderer, int x1, int y1)
{
    SDL_SetRenderDrawColor(gRenderer, 0x20 /*R*/, 0x10 /*G*/, 0xA0 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer, x1, y1, x1, y1 + 50);
    SDL_RenderDrawLine(gRenderer, x1, y1 + 50, x1 + 50, y1 + 50);
    SDL_RenderDrawLine(gRenderer, x1 + 50, y1 + 50, x1 + 50, y1);
    SDL_RenderDrawLine(gRenderer, x1 + 50, y1, x1, y1);
}
