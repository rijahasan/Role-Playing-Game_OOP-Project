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
        textboxes.erase(textboxes.begin());     //releasing memory
        return false;       //interaction has not been completed
    }
    return true;       //interaction has been completed      
}

void interactions :: drawtextbox(){        //draws first textbox from the textbox vector
    textboxes[0]->draw();
}

int interactions :: questionnum(){      //returns the current question number, it subtracts 9 from count because viva starts after 9th question
    if (count>=10)
        return count-9;
    else
        return 0;
}

int interactions :: getcount(){     //returns count 
    return count;
}

interactions :: ~interactions(){   //doesnt need to release memory because it gets released one by one as textboxes are drawn

}