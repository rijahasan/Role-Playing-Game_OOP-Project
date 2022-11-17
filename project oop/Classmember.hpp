#include<SDL.h>
#include "drawing.hpp"
//#include <string>
#pragma once

class Classmember{

    public:
    //string Name;
    SDL_Rect srcRect, moverRect;
    int count = 0;
    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
    void makeMove(int);
    Classmember();
    ~Classmember();
    void movement(SDL_Keycode);
    virtual void draw() = 0;
};