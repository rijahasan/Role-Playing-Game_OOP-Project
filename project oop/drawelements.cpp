#include "drawelements.hpp"

void drawelements :: draw (char a){
    switch(a){
        case 'I':
            SDL_RenderCopy(Drawing::gRenderer, Drawing::white, &whitesrc, &Instructionsmover);
            SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &Instructionsrc, &Instructionsmover);       //draws instruction screen
        break;
        case 'F':
            SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &fadesrc, &fademover);
        break;
        case 'C':
            SDL_RenderCopy(Drawing::gRenderer, Drawing::white, &whitesrc, &correctmover);
            SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &correctsrc, &correctmover);
        break;
        case 'T':
            SDL_RenderCopy(Drawing::gRenderer, Drawing::white, &whitesrc, &timeroutmover);
            SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &timeroutsrc, &timeroutmover);
        break;
        case 'Y':
            SDL_RenderCopy(Drawing::gRenderer, Drawing::white, &whitesrc, &ynmover);
            SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &ynsrc, &ynmover);
        break;
        case 'Q':
            SDL_RenderCopy(Drawing::gRenderer, Drawing::white, &whitesrc, &quizstartingmover);
            SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &quizstartingsrc, &quizstartingmover);
        break;
        case 'W':
            SDL_RenderCopy(Drawing::gRenderer, Drawing::white, &whitesrc, &winmover);
            SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &winsrc, &winmover);
        break;
        case 'L':
            SDL_RenderCopy(Drawing::gRenderer, Drawing::white, &whitesrc, &losemover);
            SDL_RenderCopy(Drawing::gRenderer, Drawing::moreassets, &losesrc, &losemover);
        break;   
    }
};
