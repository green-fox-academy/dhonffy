#include "draw.h"

void draw(SDL_Renderer *gRenderer)
{
    float size = 19;
    float height = size * 0.8660254;
    int levels = 480 / static_cast<int>(size);
    int offset = 320 - size / 2 * levels;

    float slopeX1 = levels * size / 2 + offset;
    float slopeY1 = 480 - levels * height;
    float slopeX2 = levels * size + offset;
    float slopeY2 = 480;
    for (int i = 0; i < levels; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0x00 /*A*/);
        SDL_RenderDrawLine(gRenderer, slopeX1 - size / 2 * i, slopeY1 + height * i, slopeX2 - size * i, slopeY2);
    }
    float riseX1 = slopeX1;
    float riseY1 = slopeY1;
    float riseX2 = offset;
    float riseY2 = slopeY2;
    for (int i = 0; i < levels; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0x00 /*A*/);
        SDL_RenderDrawLine(gRenderer, riseX1 + size / 2 * i, riseY1 + height * i, riseX2 + size * i, riseY2);
    }
    float bottomX1 = slopeX1;// - height / 2;
    float bottomY1 = slopeY1;// + height;
    float bottomX2 = bottomX1;// + height / 2;
    float bottomY2 = bottomY1;
    for (int i = 0; i <= levels; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0x00 /*A*/);
        SDL_RenderDrawLine(gRenderer, bottomX1 - size / 2 * i, bottomY1 + height * i, bottomX2 + size / 2 * i,
                           bottomY2 + height * i);
    }
}
