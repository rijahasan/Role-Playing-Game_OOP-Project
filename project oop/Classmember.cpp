#include "Classmember.hpp"
#include <iostream>


void Classmember:: moveRight()
{
    if (count == 0)
    {
        srcRect = {445, 268, 68, 81};
        count ++;
    }
    else if (count == 1)
    {
        srcRect = {434, 53, 74, 87};
        count = 0; 
    }
    moverRect.x += 10;
}

void Classmember:: moveUp()
{
    if (count == 0)
    {
        srcRect = {147, 276, 61, 82};
        count++;
    }
    else if (count == 1)
    {
        srcRect = {349, 268, 64, 82};
        //count++;
        count = 0;
    }
    moverRect.y -= 10;
}
void Classmember:: moveLeft()
{
    if (count == 0)
    {
        srcRect = {57, 76, 60, 81};
        count++;
    }
    else if (count == 1)
    {
        srcRect = {153, 51, 58, 76};
        count = 0;
    }
    moverRect.x -= 10;
}
void Classmember:: moveDown()
{
    if (count == 0)
    {
        srcRect = {145, 164, 58, 80};
        count++;
    }
    else if (count == 1)
    {
        srcRect = {64, 255, 53, 68};
        //count ++;
        count = 0;
    }

    moverRect.y += 10;
}
void Classmember:: addinteraction(SDL_Rect src, SDL_Rect mover){
    I.addtextbox(src,mover);
}

bool Classmember::  drawnextinteraction(){
    return I.drawnexttextbox();
}

void Classmember :: drawinteraction(){
    I.drawtextbox();
}

bool Classmember :: viva(){
    return false;
}



void Classmember:: movement(SDL_Keycode key)
{
    if (key == SDLK_UP) //when up pressed
    {
        makeMove(1);
    }
    else if (key == SDLK_DOWN) //when down key pressed
    {
        makeMove(2);
    }
    else if (key == SDLK_RIGHT) //when right key pressed
    {
        makeMove(3);
    }
    else if (key == SDLK_LEFT) //when left key pressed
    {
       makeMove(4);
    }
    else {
        std::cout<<"hello";
    }
}


void Classmember :: makeMove(int direction)
{
    if (direction == 1)
    {
        moveUp();
    }
    else if (direction == 2)
    {
        moveDown();
    }
    else if (direction == 3)
    {
        moveRight();
    }
    else if (direction == 4)
    {
        moveLeft();
    }
    else
    {
       std::cout<<"press a key";
    }
}


Classmember:: Classmember()
{

}

Classmember:: ~Classmember()
{

}