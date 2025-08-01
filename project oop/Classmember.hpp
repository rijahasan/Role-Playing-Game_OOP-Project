#include<SDL.h>
#include "drawing.hpp"
#include "interactions.hpp"

//#include <string>
#pragma once

class Classmember{
    public:
    interactions I;     //each classmember have their own set of defined interactions
    SDL_Rect srcRect, srcRectF, moverRect, srcRectB;       //srcRectB represents back side of the sprite while srcRectF represents front side 
    int count = 0;      //checks the orientation of the classmember
    void moveDown();    //moves down 
    void moveUp();  //moves down 
    void moveRight();   //moves right
    void moveLeft();        //moves left 
    void makeMove(int);     
    bool turned=false;      //if the class member is turned or not
    Classmember();
    ~Classmember();

    void movement(SDL_Keycode);
    // virtual void addinteraction() = 0;
    virtual void draw()=0;
    virtual bool viva();
    void addinteraction(SDL_Rect, SDL_Rect);
    bool drawnextinteraction();
    void drawinteraction();
};