#include<SDL.h>
#include "drawing.hpp"
#include <string>
#include <vector>

#include "textbox.hpp"

using namespace std;




class interactions{
    vector <textbox*> textboxes;
    vector <bool> interacted;
    public:
    int count=0;
    interactions();
    void addtextbox(SDL_Rect, SDL_Rect);
    void drawtextbox();
    bool drawnexttextbox();     //returns false if the textbox is empty
    int questionnum();
    ~interactions();

};

