#pragma once
#include<SDL.h>
#include "textbox.hpp"


void textbox :: draw ()
{
     SDL_RenderCopy(Drawing::gRenderer, Drawing::textboxes, &srcRect, &moverRect);
}



textbox :: textbox()
{
    srcRect = {21, 29, 752, 134};
    moverRect = {5, 5, 752, 134};
}

textbox :: textbox(SDL_Rect src, SDL_Rect mover)
{
    srcRect = src;
    moverRect = mover;
    // txt=inputtxt;
}