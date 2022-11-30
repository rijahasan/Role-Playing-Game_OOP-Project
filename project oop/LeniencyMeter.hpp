#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include <string>
using namespace std;


class LeniencyMeter{
    int meter=0;
    public:
    SDL_Rect srcRect, moverRect;
    void  draw ();
    bool IncreaseLeniency();
    LeniencyMeter();
};

