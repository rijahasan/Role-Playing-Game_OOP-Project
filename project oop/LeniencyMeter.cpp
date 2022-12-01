#include<SDL.h>
#include "LeniencyMeter.hpp"


void LeniencyMeter :: draw ()
{
     SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &srcRect, &moverRect);
}

bool LeniencyMeter :: IncreaseLeniency(){
    switch (meter){
        case 0:
            srcRect={0,98,673,31};
            meter=1;
        break;
        case 1:
            srcRect={0, 196, 673, 31};
            meter=2;
        break;
        case 2:
            srcRect={0, 295, 673, 30};
            meter=3;
        break;
        case 3:
            srcRect={0, 393, 673, 31};
            meter=4;
            return true;
        break;
    }
    return false;
}

LeniencyMeter :: LeniencyMeter()
{
    moverRect={85, 55, 217, 10};
    srcRect={0, 0, 673, 31};
    meter=0;
}




