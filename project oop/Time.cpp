#include<SDL.h>
#include "Time.hpp"


void Time :: draw ()
{
     SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &srcRect, &moverRect);
}

void Time :: IncreaseTime(int a){
    if (a==50){
        srcRect={0, 443, 673, 31};
    }
    else if (a==200){
        srcRect={0, 544, 673, 31};
    }
    else if (a==350){
        srcRect={0, 643, 673, 30};
    }
    else if (a==500){
        srcRect={0, 741, 673, 31};
    }
    else if (a==750){
        srcRect={0, 842, 673, 31};
    }
    else if (a==900){
        srcRect={0, 940, 673, 31};
    }
    else if (a==1050){
        srcRect={0, 1039, 673, 31};
    }
    else if (a==1200){
        srcRect={0, 1137, 673, 30};
    }
    else if (a==1350){
        srcRect={0, 1253, 673, 31};
    }
    else if (a==1500){
        srcRect={0, 1351, 673, 31};
    }
    else if (a==1650){
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




