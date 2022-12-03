#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include <string>
using namespace std;


class Time{
    public:
    SDL_Rect srcRect, moverRect;
    int seconds=0;
    void  draw ();
    void IncreaseTime(int);
    bool timerout();
    void operator ++();       //adds seconds to time
    Time();
};

