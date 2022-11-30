#include<SDL.h>
#include "interactions.hpp"


interactions :: interactions(){
    
}


void interactions :: addtextbox(SDL_Rect src, SDL_Rect mover){
    textboxes.push_back(new textbox(src,mover));
}

bool interactions :: drawnexttextbox(){
    if (textboxes.empty()==false) //checks if the vector is empty
    {
        textboxes[0]->draw();
        count++;
        textboxes.erase(textboxes.begin());
        return false;       //interaction has not been completed
    }
    return true;       //interaction has been completed
}

void interactions :: drawtextbox(){
    textboxes[0]->draw();
}

int interactions :: getcount(){
    return count;
}

interactions :: ~interactions(){
    
}
