#include "draw.h"
#include <iostream>
#include <vector>

void drawSteps(SDL_Renderer*, int);

void draw(SDL_Renderer *gRenderer)
{
    // Reproduce this:
    //  [https://github.com/green-fox-academy/teaching-materials/blob/master/workshop/drawing/assets/r4.png]
    // Pay attention for the outlines as well
    int steps = 3;
    drawSteps(gRenderer, steps);
}

void drawSteps(SDL_Renderer *gRenderer, int steps)
{
    if (steps > 9) {
        steps = 9;
    }
    int previousStartPoint = 10;
    int previousSize = 0;
    int size;
    int startPoint = previousStartPoint + previousSize;
    int sizeFilled = size - 2;
    int startPointFilled = startPoint + 1;

    for (int i = 0; i < steps; ++i) {
        size = 10 + i * 10;
        startPoint = previousStartPoint + previousSize - 1;
        sizeFilled = size - 2;
        startPointFilled = startPoint + 1;
        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0x00 /*A*/);
        SDL_Rect fillRectOutline = {startPoint, startPoint, size, size};
        SDL_RenderDrawRect(gRenderer, &fillRectOutline);
        SDL_SetRenderDrawColor(gRenderer, 138 /*R*/, 43 /*G*/, 226 /*B*/, 0x00 /*A*/);
        SDL_Rect fillRect = {startPointFilled, startPointFilled, sizeFilled, sizeFilled};
        SDL_RenderFillRect(gRenderer, &fillRect);
        previousStartPoint = startPoint;
        previousSize = size;
    }
}