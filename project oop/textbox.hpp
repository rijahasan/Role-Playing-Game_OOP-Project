#include<SDL.h>
#include "drawing.hpp"
#include<string>


class textbox{
    public:
    SDL_Rect srcRect, moverRect;
    string txt;
    void draw();
    textbox();
    textbox(int, int, string);
};

