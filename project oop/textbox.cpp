#include<SDL.h>
#include "textbox.hpp"


void textbox :: draw ()
{
     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}


textbox :: textbox()
{
    srcRect = {226, 122, 179, 129};
    moverRect = {5, 400, 120, 90};
}

textbox :: textbox(SDL_Rect src, SDL_Rect mover)
{
    srcRect = src;
    moverRect = mover;
    // txt=inputtxt;
}