#include "faculty.hpp"
#pragma once

faculty :: faculty()
{
    srcRect = {426, 157, 61, 94};
    moverRect = {500, 90, 50, 60};
}

faculty :: faculty(int x, int y)
{
    srcRect = {426, 157, 61, 94};
    moverRect = {x, y, 60, 75};
}

void faculty :: draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}


