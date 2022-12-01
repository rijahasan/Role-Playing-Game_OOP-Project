#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include <string>
using namespace std;


class LeniencyMeter{
    int meter=0;
    public:
    SDL_Rect srcRect={};
    SDL_Rect moverRect={};
    bool full=false;
    void  draw ();
    void operator ++();
    LeniencyMeter();
};

