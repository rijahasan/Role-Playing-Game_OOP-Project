#include "students.hpp"

void students :: draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

students :: students()
{
    srcRect = {147, 276, 61, 82};
    moverRect = {60, 400, 60, 75};
}

students :: students(int x, int y)
{
    srcRect = {147, 276, 61, 82};
    moverRect = {x, y, 60, 70};
}