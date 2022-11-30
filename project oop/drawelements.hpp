#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include <string>
using namespace std;

class drawelements{
    SDL_Rect Instructionsrc={733, 575, 1015, 1330}, Instructionsmover={268, 125, 471, 410}, 
    fadesrc={729,31,1244,294}, fademover={0,490,1000,110}, correctsrc={}, correctmover={}, wrongsrc, wrongmover, ynsrn, ynmover, quizstartingsrc, quizstartingmover, winsrc, winmover, losesrc, losemover,
    whitesrc={196,211,612,578};
    public:
    void  draw (char);
};

