#include "desk.hpp"

void desk :: draw ()
{
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