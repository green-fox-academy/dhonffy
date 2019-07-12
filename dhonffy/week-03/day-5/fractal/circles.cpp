#include "draw.h"
void setColor(SDL_Renderer *, int, int, int);
void drawCircle(SDL_Renderer *, int, int, int, int);
void drawCircles(SDL_Renderer *gRenderer, int depth);

void draw(SDL_Renderer* gRenderer)
{
    //circles
    setColor(gRenderer, 0x00, 0x00, 0x00);
    drawCircles(gRenderer, 0);
}

void drawCircles(SDL_Renderer *gRenderer, int depth)
{
    drawCircle(gRenderer, 450, 450, 450, depth);
}

void setColor(SDL_Renderer *gRenderer, int r, int g, int b)
{
    SDL_SetRenderDrawColor(gRenderer, r /*R*/, g /*G*/, b /*B*/, 0xFF /*A*/);
}
void drawCircle(SDL_Renderer *gRenderer, int x1, int y1, int r, int depth)
{
    if (depth == 6){
        return;
    }
    int centreX = x1;
    int centreY = y1;
    int radius = r;
    int x = (radius - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int diameter = radius * 2;
    int error = (tx - diameter);
    while (x >= y) {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(gRenderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(gRenderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(gRenderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(gRenderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(gRenderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(gRenderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(gRenderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(gRenderer, centreX - y, centreY + x);

        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
    drawCircle(gRenderer, x1, y1 - r / 2, radius / 2, depth + 1);
    drawCircle(gRenderer, x1 - radius * 353 / 1000, y1 + radius * 353 / 1000, radius / 2, depth + 1);
    drawCircle(gRenderer, x1 + radius * 353 / 1000, y1 + radius * 353 / 1000, r / 2, depth + 1);
}