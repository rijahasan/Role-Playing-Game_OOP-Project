#include<SDL.h>
#include "drawing.hpp"

class desk{

    SDL_Rect srcRect, moverRect;

    public:
    void draw();
    desk();
    desk(int, int);
    ~desk();
};