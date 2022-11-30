#include<SDL.h>
#include "Time.hpp"


void Time :: draw ()
{
     SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &srcRect, &moverRect);
}

void Time :: IncreaseTime(int a){
    if (a==80){
        srcRect={35, 141, 130, 7};
        }
    else if (a==190){
        srcRect={35, 141, 130, 7};
        }
    else if (a==270){
        srcRect={35, 161, 130, 6};
    }
    else if (a==360){
        srcRect={35, 180, 130, 6};
    }
    else if (a==450){
        srcRect={35, 180, 130, 6};
    }
    else if (a==540){
        srcRect={35, 180, 130, 6};
    }
    else if (a==630){
        srcRect={35, 180, 130, 6};
    }
    else if (a==720){
        srcRect={35, 180, 130, 6};
    }
    else if (a==810){
        srcRect={35, 180, 130, 6};
    }   
}

Time :: Time()
{
    moverRect={85, 35, 217, 10};
    srcRect={0, 0, 673, 31};

}

