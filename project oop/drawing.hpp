#include<SDL.h>
#pragma once
class Drawing{
    public:
        //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets

    static SDL_Texture* assets;
    static SDL_Texture* classmates;
    static SDL_Texture* textboxes;
    static SDL_Texture* lentime;

};