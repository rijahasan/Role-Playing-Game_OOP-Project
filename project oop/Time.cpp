#include<SDL.h>
#include "Time.hpp"


void Time :: draw (){
     SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &srcRect, &moverRect);
}

void Time :: operator ++ (){        //increment ooperator is overloaded to change the timer to change srcRect to a longer time bar
    switch (seconds){   //checks the variable seconds
        case 50:
        srcRect={0, 443, 673, 31};
        break;
        case 100:
        srcRect={0, 544, 673, 31};
        break;
        case 200:
        srcRect={0, 643, 673, 30};
        break;
        case 250:
        srcRect={0, 741, 673, 31};
        break;
        case 300:
        srcRect={0, 842, 673, 31};
        break;
        case 350:
        srcRect={0, 940, 673, 31};
        break;
        case 400:
        srcRect={0, 1039, 673, 31};
        break;
        case 450:
        srcRect={0, 1137, 673, 30};
        break;
        case 500:
        srcRect={0, 1253, 673, 31};
        break;
        case 550:
        srcRect={0, 1351, 673, 31};
        break;
        case 600:
        srcRect={0, 1449, 673, 31};
        break;
    }   

}

bool Time :: timerout(){        //checks if the timer has run out or not 
    if (seconds>=600)
        return true;        //returns true if it has, false, if not 
    return false;
}

Time :: Time()
{
    moverRect={85, 35, 217, 10};
    srcRect={0, 0, 673, 31};        //empty time bar, made on object construction
}




