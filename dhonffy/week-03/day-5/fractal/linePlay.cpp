#include "draw.h"

void draw(SDL_Renderer *gRenderer)
{
    int x1 = 90;
    int y1 = 0;
    int x2 = 560;
    int y2 = 0;
    for (int i = 0; i < 23 ; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 0xC7 /*R*/, 0x15 /*G*/, 0x85 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, x1 + 20 * i, y1, x2, y2 + 20 * i);
    }
    x1 = 80;
    y1 = 10;
    x2 = 80;
    y2 = 480;
    for (int i = 0; i < 23 ; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 0x74 /*R*/, 0xD4 /*G*/, 0x44 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, x1, y1 + 20 * i, x2 + 20 * i, y2);
    }

}
