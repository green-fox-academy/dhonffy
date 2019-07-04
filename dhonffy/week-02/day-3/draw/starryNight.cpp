#include "draw.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void draw(SDL_Renderer *gRenderer)
{
    // Draw the night sky:
    //  - The background should be black
    //  - The stars can be small squares
    //  - The stars should have random positions on the canvas
    //  - The stars should have random color (some shade of grey)
    //
    // You might have to make modifications somewhere else to create a black background ;)
    srand(time(NULL));
    int amount = rand() % 200;
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(gRenderer);

    for (int i = 0; i < amount; ++i) {
        int red = rand() % 256;
        int green = red;
        int blue = red;
        int x1 = rand() % 640;
        int y1 = rand() % 480;
        SDL_SetRenderDrawColor(gRenderer, red /*R*/, green /*G*/, blue /*B*/, 0x00 /*A*/);
        SDL_Rect fillRectOutline = {x1, y1, 5, 5};
        SDL_RenderFillRect(gRenderer, &fillRectOutline);
    }
}
