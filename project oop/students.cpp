#include "students.hpp"


students :: students()
{
    srcRect = {147, 276, 61, 82};
    moverRect = {60, 400, 60, 75};
}

students :: students(int x, int y)
{
    srcRect = {147, 276, 61, 82};
    moverRect = {x, y, 60, 70};
}
SDL_Rect students :: getter() const
{
    return moverRect;
}

// void students :: addinteraction(SDL_rect src, SDL_rect mover){
//     I.addtextbox(src,mover);