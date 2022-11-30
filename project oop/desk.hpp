#include<SDL.h>
#include "drawing.hpp"
#pragma once
class desk{

    SDL_Rect srcRect, moverRect;

    public:
    bool iswindow=false;
    void draw();
    SDL_Rect getter();
    desk();
    desk(int, int);
    ~desk();
    desk(SDL_Rect , SDL_Rect );
};