#include <iostream>
#include "Oopdastaan.hpp"

void Oopdastaan::drawObjects()
{
    /* d1->draw();
    d2->draw();
    d3->draw();
    d4->draw();
    d5->draw();
    d6->draw();
    d7->draw();
    d8->draw();
    d9->draw(); */
    f1->draw();
    s1->draw();
    s2->draw();
    s3->draw();
    s4->draw();
    s5->draw();
    s6->draw();
    s7->draw();
    s8->draw();
    //s9->draw();
   /*  SDL_Event ev;
    while( SDL_PollEvent( &ev ) != 0)
    {
        if(ev.type == SDL_KEYDOWN){
            cout << "down";
            s9->movement(ev.key.keysym.sym);
        }
        else 
        {
            cout << ev.type;
            s9->movement(ev.key.keysym.sym);
        }
    }
    
     */
 
}

void Oopdastaan::createObject()
{
    //std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;

    /* d1 = new desk(100, 450);
    desks.push_back(d1);
    d2 = new desk(780, 450);
    desks.push_back(d2);
    d3 = new desk(290, 350);
    desks.push_back(d3);
    d4 = new desk(590, 350);
    desks.push_back(d4);
    d5 = new desk(50, 250);
    desks.push_back(d5);
    d6 = new desk(830, 250);
    desks.push_back(d6);
    d7 = new desk(280, 150);
    desks.push_back(d7);
    d8 = new desk(600, 150);
    desks.push_back(d8);
    d9 = new desk(440,25);
    desks.push_back(d9); */
    f1 = new faculty(470, 0);
    s1 = new students(130,490);
    s2 = new students(810, 490);
    s3 = new students(320, 390);
    s4 = new students(620,390);
    s5 = new students(80, 290);
    s6 = new students(860, 290);
    s7 = new students(310, 190);
    s8 = new students(630, 190);
    //s9 = new students(20, 510);


}

Oopdastaan:: ~Oopdastaan()
{
    /*
    for (int i = 0; i < pigeons.size(); i++) //this deletes all the pointers of vector and then clears the vector
    {
        delete pigeons[i];
        pigeons.clear();
    }

    for (int j = 0; j < bees.size(); j++)
    {
        delete bees[j];
        bees.clear();
    }

    for (int k = 0; k < butterflies.size(); k++)
    {
        delete butterflies[k];
        butterflies.clear();
    }
    */
}