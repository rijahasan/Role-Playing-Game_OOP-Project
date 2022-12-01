#include<SDL.h>
#include "Time.hpp"


void Time :: draw ()
{
     SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &srcRect, &moverRect);
}

void Time :: IncreaseTime(int a){
    if (a==40){
        srcRect={0, 544, 673, 31};
    }
    else if (a==80){
        srcRect={0, 643, 673, 30};
    }
    else if (a==50){
        srcRect={0, 741, 673, 31};
    }
    else if (a==100){
        srcRect={0, 842, 673, 31};
    }
    else if (a==250){
        srcRect={0, 940, 673, 31};
    }
    else if (a==400){
        srcRect={0, 1039, 673, 31};
    }
    else if (a==550){
        srcRect={0, 1137, 673, 30};
    }
    else if (a==700){
        srcRect={0, 1253, 673, 31};
    }
    else if (a==850){
        srcRect={0, 1351, 673, 31};
    }
    else if (a==1000){
        srcRect={0, 1449, 673, 31};
    }   
}
bool Time :: timerout(int s){
    if (s>=1500)
        return true;
    return false;
}

Time :: Time()
{
    moverRect={85, 35, 217, 10};
    srcRect={0, 0, 673, 31};
;

}




