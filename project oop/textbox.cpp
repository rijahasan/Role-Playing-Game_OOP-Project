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

textbox :: textbox(int x, int y, string inputtxt)
{
    srcRect = {226, 122, 179, 129};
    moverRect = {x, y, 120, 90};
    txt=inputtxt;
}