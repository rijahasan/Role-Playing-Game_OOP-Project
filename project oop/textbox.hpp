#include<SDL.h>
#include "drawing.hpp"
#include <string>
using namespace std;


class textbox{
    public:
    SDL_Rect srcRect, moverRect;
    void  draw ();
    textbox();
    textbox(SDL_Rect, SDL_Rect);
};

