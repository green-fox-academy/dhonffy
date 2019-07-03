#include "draw.h"
#include <iostream>
#include <vector>

void drawSteps(SDL_Renderer*, std::vector<int>);

void draw(SDL_Renderer *gRenderer)
{
    // Reproduce this:
    // [https://github.com/green-fox-academy/teaching-materials/blob/master/workshop/drawing/assets/r3.png]
    // Pay attention for the outlines as well
    std::vector<int> colors = {138, 43, 226};
    drawSteps(gRenderer, colors);
}

void drawSteps(SDL_Renderer *gRenderer, std::vector<int> colors)
{
    for (int i = 0; i < 190; i += 10) {
        SDL_SetRenderDrawColor(gRenderer, colors[0] /*R*/, colors[1] /*G*/, colors[2] /*B*/, 0x00 /*A*/);
        SDL_Rect fillRect = {10 + i, 10 + i , 10, 10};
        SDL_RenderFillRect(gRenderer, &fillRect);
    }
}