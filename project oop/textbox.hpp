#include<SDL.h>
#include "drawing.hpp"
#include <string>
using namespace std;




class textbox{
    public:
    SDL_Rect srcRect, moverRect;
    string txt;
    void draw();
    textbox();
    textbox(int, int, string);
};

