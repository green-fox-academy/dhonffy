#include "draw.h"

void draw(SDL_Renderer* gRenderer)
{
//choose color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
//create a rectangle
    SDL_Rect fillRect = { 100, 100, 20, 50};
//draw rectangle
    SDL_RenderFillRect( gRenderer, &fillRect );
}