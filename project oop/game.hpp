
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "SDL_ttf.h"
#include "textbox.hpp"
#include "drawing.hpp"
#include "drawelements.hpp"


#pragma once
using namespace std;
class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    Mix_Music *bgMusic = NULL;
    Mix_Chunk *RightansMusic = NULL;
    Mix_Chunk *WrongansMusic = NULL;
    

public:

    
    bool check=false;
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};

