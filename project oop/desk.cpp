#include "desk.hpp"
#include<list>

void desk :: draw ()
{
    if (iswindow)
         SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &srcRect, &moverRect);
    else
         SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);

}

desk :: desk()
{
    srcRect = {226, 122, 179, 129};
    moverRect = {5, 400, 120, 90};
}

desk :: desk(int x, int y)
{
    srcRect = {226, 122, 179, 129};
    moverRect = {x, y, 120, 90};
}

desk :: desk(SDL_Rect src, SDL_Rect mover)      //constructor overloading, different srcRect for window
{
    srcRect = src ;
    moverRect = mover;
    iswindow=true;     //if the object made is of the window
}

SDL_Rect desk :: getter()
{
    return moverRect;
}

desk :: ~desk(){
    
}
