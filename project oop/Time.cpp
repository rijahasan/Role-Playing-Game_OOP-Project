#include<SDL.h>
#include "Time.hpp"


void Time :: draw ()
{
     SDL_RenderCopy(Drawing::gRenderer, Drawing::lentime, &srcRect, &moverRect);
}


void Time :: IncreaseTime(int a){
    if (a<5){
        srcRect={35, 104, 130, 5};
    }
    if (a<30){
        srcRect={35, 122, 130, 6};
    }
    else if (a<60){
        srcRect={35, 141, 130, 7};
        }
    else if (a<90){
        srcRect={35, 161, 130, 6};
    }
    else if (a<=120){
        srcRect={35, 180, 130, 6};
    }
}

Time :: Time()
{
    moverRect={85, 35, 217, 10};
    srcRect={35, 104, 130, 5};

}

