#include "Classmember.hpp"
#include <iostream>

void Classmember :: draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

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
    /* if (moverRect.x >= 100 && moverRect.x <= 220)
    {
        if (moverRect.y >= 360 && moverRect.y <= 450)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else if (moverRect.x >= 780 && moverRect.x <= 900)
    {
        if (moverRect.y >= 360 && moverRect.y <= 450)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else if (moverRect.x >= 290 && moverRect.x <= 410)
    {
        if (moverRect.y >= 260 && moverRect.y <= 350)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else if (moverRect.x >= 590 && moverRect.x <= 710)
    {
        if (moverRect.y >= 260 && moverRect.y <= 350)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else if (moverRect.x >= 50 && moverRect.x <= 170)
    {
        if (moverRect.y >= 160 && moverRect.y <= 260)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else if (moverRect.x >= 830 && moverRect.x <= 950)
    {
        if (moverRect.y >= 160 && moverRect.y <= 250)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else if (moverRect.x >= 280 && moverRect.x <= 400)
    {
        if (moverRect.y >= 60 && moverRect.y <= 150)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else if (moverRect.x >= 600 && moverRect.x <= 720)
    {
        if (moverRect.y >= 60 && moverRect.y <= 150)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else if (moverRect.x >= 440 && moverRect.x <= 560 )
    {
        if (moverRect.y >= 25 && moverRect.y <= 115)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y -= 10;
        }
    }
    else 
    {
        moverRect.y -= 10;
    } */
    // else if (count == 2)
    // {
    //     srcRect = {251, 277, 62, 80};
    //     count = 0;
    // }
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
    /* if (moverRect.x >= 100 && moverRect.x <= 220)
    {
        if (moverRect.y >= 450 && moverRect.y <= 540)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else if (moverRect.x >= 780 && moverRect.x <= 900)
    {
        if (moverRect.y >= 450 && moverRect.y <= 540)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else if (moverRect.x >= 290 && moverRect.x <= 410)
    {
        if (moverRect.y >= 350 && moverRect.y <= 440)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else if (moverRect.x >= 590 && moverRect.x <= 710)
    {
        if (moverRect.y >= 350 && moverRect.y <= 440)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else if (moverRect.x >= 50 && moverRect.x <= 170)
    {
        if (moverRect.y >= 250 && moverRect.y <= 340)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else if (moverRect.x >= 830 && moverRect.x <= 950)
    {
        if (moverRect.y >= 250 && moverRect.y <= 340)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else if (moverRect.x >= 280 && moverRect.x <= 400)
    {
        if (moverRect.y >= 150 && moverRect.y <= 240)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else if (moverRect.x >= 600 && moverRect.x <= 720)
    {
        if (moverRect.y >= 150 && moverRect.y <= 240)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else if (moverRect.x >= 440 && moverRect.x <= 560 )
    {
        if (moverRect.y >= 25 && moverRect.y <= 115)
        {
             moverRect.y += 0;
        }
        else 
        {
            moverRect.y += 10;
        }
    }
    else 
    {
        moverRect.y += 10;
    } */
    // else if (count == 2)
    // {
    //     srcRect = {65, 162, 54, 82};
    //     count = 0;
    // }
    moverRect.y += 10;
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