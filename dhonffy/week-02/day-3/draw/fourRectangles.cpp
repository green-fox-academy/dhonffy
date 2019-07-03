#include "draw.h"

void setColor(SDL_Renderer *, int, int, int);

void drawRectangle(SDL_Renderer *, int, int, int, int);

void draw(SDL_Renderer *gRenderer)
{
    // Exercise:
    // draw four different size and color rectangles.
    // avoid code duplication.
    int x1 = 50;
    int y1 = 50;
    int a = 30;
    int b = 25;
    int red = 0x00;
    int green = 0xff;
    int blue = 0x88;
    setColor(gRenderer, red, green, blue);
    drawRectangle(gRenderer, x1, y1, a, b);
    x1 = 150;
    y1 = 150;
    a = 50;
    b = 55;
    red = 0x20;
    green = 0x4f;
    blue = 0x08;
    setColor(gRenderer, red, green, blue);
    drawRectangle(gRenderer, x1, y1, a, b);
    x1 = 250;
    y1 = 250;
    a = 90;
    b = 85;
    red = 0x90;
    green = 0x0f;
    blue = 0x68;
    setColor(gRenderer, red, green, blue);
    drawRectangle(gRenderer, x1, y1, a, b);
    x1 = 350;
    y1 = 350;
    a = 100;
    b = 25;
    red = 0x10;
    green = 0x00;
    blue = 0xff;
    setColor(gRenderer, red, green, blue);
    drawRectangle(gRenderer, x1, y1, a, b);
}

void setColor(SDL_Renderer *gRenderer, int r, int g, int b)
{
    SDL_SetRenderDrawColor(gRenderer, r /*R*/, g /*G*/, b /*B*/, 0xFF /*A*/);
}

void drawRectangle(SDL_Renderer *gRenderer, int x1, int y1, int a, int b)
{
    SDL_Rect fillRect = {x1, y1, a, b};
    SDL_RenderFillRect(gRenderer, &fillRect);
}
