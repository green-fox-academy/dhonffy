#include "draw.h"
#include <iostream>
#include <vector>

void drawSteps(SDL_Renderer*);

void draw(SDL_Renderer *gRenderer)
{
    // Reproduce this:
    // [https://github.com/green-fox-academy/teaching-materials/blob/master/workshop/drawing/assets/r3.png]
    // Pay attention for the outlines as well
    drawSteps(gRenderer);
}

void drawSteps(SDL_Renderer *gRenderer)
{
    for (int i = 0; i < 190; i += 10) {
        SDL_SetRenderDrawColor(gRenderer, 138 /*R*/, 43 /*G*/, 226 /*B*/, 0x00 /*A*/);
        SDL_Rect fillRect = {11 + i, 11 + i , 8, 8};
        SDL_RenderFillRect(gRenderer, &fillRect);
        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0x00 /*A*/);
        SDL_Rect fillRectOutline = {10 + i, 10 + i , 10, 10};
        SDL_RenderDrawRect(gRenderer, &fillRectOutline);
    }
}