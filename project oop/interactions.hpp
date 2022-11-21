#include<SDL.h>
#include "drawing.hpp"
#include <string>
#include <vector>

#include "textbox.hpp"

using namespace std;




class interactions{
    vector <textbox*> textboxes;
    public:
    interactions();
    void addtextbox(SDL_Rect, SDL_Rect);

};

