#include "faculty.hpp"
#pragma once
using namespace std;

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


bool faculty :: viva(){
    cout<<I.questionnum();
    if (I.questionnum()>=1)
        return true;
    return false;
}