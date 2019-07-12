#include "draw.h"
void setColor(SDL_Renderer *, int, int, int);
void drawRectangle(SDL_Renderer *, int, int, int, int, int depth);
void drawCarpet(SDL_Renderer* gRenderer);

void draw(SDL_Renderer* gRenderer)
{
    // Sierpinsky carpet
    setColor(gRenderer, 0x00, 0x00, 0x00);
    drawCarpet(gRenderer);
}

void drawCarpet(SDL_Renderer* gRenderer)
{
    drawRectangle(gRenderer, 0, 0, 900, 900, 0);
}

void setColor(SDL_Renderer *gRenderer, int r, int g, int b)
{
    SDL_SetRenderDrawColor(gRenderer, r /*R*/, g /*G*/, b /*B*/, 0xFF /*A*/);
}
void drawRectangle(SDL_Renderer *gRenderer, int x1, int y1, int a, int b, int depth)
{
    if (depth == 6){
        return;
    }
    SDL_Rect fillRect = {(x1 + a) / 3, (y1 + b) / 3, a / 3, b / 3};
    SDL_RenderFillRect(gRenderer, &fillRect);
    drawRectangle(gRenderer, x1, y1, a / 3, b / 3, depth + 1); //bal felső
    drawRectangle(gRenderer, x1 + a, y1, a / 3, b / 3, depth + 1); //felső
    drawRectangle(gRenderer, x1 + 2 * a, y1, a / 3, b / 3, depth + 1); //jobb felső
    drawRectangle(gRenderer, x1, y1 + b, a / 3, b / 3, depth + 1); //bal
    drawRectangle(gRenderer, x1, y1 + 2 * b, a / 3, b / 3, depth + 1); //bal alsó
    drawRectangle(gRenderer, x1 + a, y1 + 2 * b, a / 3, b / 3, depth + 1); //alsó
    drawRectangle(gRenderer, x1 + 2 * a, y1 + 2 * b, a / 3, b / 3, depth + 1); //jobb alsó
    drawRectangle(gRenderer, x1 + 2 * a, y1 + b, a / 3, b / 3, depth + 1); //jobb
}