#include "draw.h"

void draw(SDL_Renderer *gRenderer)
{
    // Exercise:
    // draw four different size and color rectangles.
    // avoid code duplication.
    int x1 = 50;
    int y1 = 50;
    int a = 30;
    int b = 25;
    for (int i = 0; i < 4; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 0x20 + i * 32 /*R*/, 0x10 + i * 52 /*G*/, 0xA0 + i * 8 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, (x1 + i * 60), (y1 + i * 80), (x1 + i * 60), (y1 + i * 80) + (a + i * 12));
        SDL_RenderDrawLine(gRenderer, (x1 + i * 60), (y1 + i * 80) + (a + i * 12), (x1 + i * 60) + (b + i * 10),
                           (y1 + i * 80) + (a + i * 12));
        SDL_RenderDrawLine(gRenderer, (x1 + i * 60) + (b + i * 10), (y1 + i * 80) + (a + i * 12),
                           (x1 + i * 60) + (b + i * 10), (y1 + i * 80));
        SDL_RenderDrawLine(gRenderer, (x1 + i * 60) + (b + i * 10), (y1 + i * 80), (x1 + i * 60), (y1 + i * 80));
    }
}

