#include "draw.h"

void draw(SDL_Renderer *gRenderer)
{
    // Fill the canvas with a checkerboard pattern
    int x1 = 0;
    int y1 = 0;
    for (int j = 0; j < 8; ++j) {
        for (int i = 0; i < 8; ++i) {
            if ((i + j) % 2 == 0) {
                SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0x00 /*A*/);
            } else {
                SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0xFF /*G*/, 0xFF /*B*/, 0x00 /*A*/);
            }
            SDL_Rect fillRectOutline = {x1 + i * 80, y1 + j * 60, 80, 60};
            SDL_RenderFillRect(gRenderer, &fillRectOutline);
        }
    }
}
