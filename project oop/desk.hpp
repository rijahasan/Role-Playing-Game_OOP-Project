#include<SDL.h>
#include "drawing.hpp"
#pragma once
class desk{

    SDL_Rect srcRect, moverRect;

    public:
    void draw();
    SDL_Rect getter();
    desk();
    desk(int, int);
    ~desk();
};