#include "students.hpp"


students :: students()
{
    srcRect = {147, 276, 61, 82};
    moverRect = {60, 400, 60, 75};
}

students :: students(SDL_Rect srcF, SDL_Rect srcB, int x, int y)
{
    srcRectF = srcF;
    srcRectB = srcB;
    moverRect = {x, y, 60, 70};
}
students :: students(int x, int y)
{
    srcRect = {147, 276, 61, 82};
    moverRect = {x, y, 60, 70};
    ismaincharacter=true;
}

SDL_Rect students :: getter() const
{
    return moverRect;
}

void students :: draw()
{
    if (ismaincharacter==true)
        SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
   else {
        if (turned==false)
            SDL_RenderCopy(Drawing::gRenderer, Drawing::classmates, &srcRectB, &moverRect);
        else
            SDL_RenderCopy(Drawing::gRenderer, Drawing::classmates, &srcRectF, &moverRect);
        }
}


// void students :: addinteraction(SDL_rect src, SDL_rect mover){
//     I.addtextbox(src,mover);