#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include <string>
using namespace std;

class drawelements{
    SDL_Rect Instructionsrc={733, 575, 1015, 1330};
    SDL_Rect Instructionsmover={268, 125, 471, 410};
    SDL_Rect fadesrc={729,31,1244,294};
    SDL_Rect fademover={0,450,1000,210};
    SDL_Rect correctsrc={732,352,306,56};
    SDL_Rect correctmover={300,500,286,36};
    SDL_Rect ynsrc={734, 423, 836, 56};
    SDL_Rect ynmover={300,500,138,20}; 
    SDL_Rect quizstartingsrc={737,496,979,56};
    SDL_Rect quizstartingmover={300,500,286,36};
    SDL_Rect winsrc={156,1500,480,211};
    SDL_Rect winmover={157,225,480,211};
    SDL_Rect timeoutsrc={157, 1728, 480, 105};
    SDL_Rect timeoutmover={157,225,685,150};
    SDL_Rect losesrc={156,1853, 480, 105};
    SDL_Rect losemover={157,225,685,150};
    SDL_Rect whitesrc={196,211,612,578};
    
    public:
    void  draw (char);
};

