#include<SDL.h>
#include "interactions.hpp"


interactions :: interactions(){
    
}


void interactions :: addtextbox(SDL_Rect src, SDL_Rect mover){
    textboxes.push_back(new textbox(src,mover));
}