#include "draw.h"
#include <iostream>
#include <vector>

void drawRainbowBox(SDL_Renderer *, int, std::vector<int>);

void draw(SDL_Renderer *gRenderer)
{
    // Create a square drawing function that takes 2 parameters:
    // The square size, and the fill color,
    // and draws a square of that size and color to the center of the canvas.
    // Create a loop that fills the canvas with a rainbow of colored squares.
    int size = 400;
    std::vector<int> colors = {0xff, 0x55, 0x00};
    drawRainbowBox(gRenderer, size, colors);
}

void drawRainbowBox(SDL_Renderer *gRenderer, int size, std::vector<int> colors)
{
    int halfSize;
    int red = colors[0];
    int green = colors[1];
    int blue = colors[2];
    while (size >= 2) {
        halfSize = size / 2;
        SDL_SetRenderDrawColor(gRenderer, red /*R*/, green /*G*/, blue /*B*/, 0x00 /*A*/);
        SDL_Rect fillRect = {320 - halfSize, 240 - halfSize, size, size};
        SDL_RenderFillRect(gRenderer, &fillRect);
        red += 0x20;
        green += 0x25;
        blue += 0x35;
        size -= 10;
        if (colors[0] >= 0xff) {
            colors[0] -= 0xff;
        }
        if (colors[1] >= 0xff) {
            colors[1] -= 0xff;
        }
        if (colors[2] >= 0xff) {
            colors[2] -= 0xff;
        }
    }
}
