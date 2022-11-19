#include <iostream>
#include "Oopdastaan.hpp"

void Oopdastaan::drawObjects()
{
    D[0]->draw();
    D[1]->draw();
    D[2]->draw();
    D[3]->draw();
    D[4]->draw();
    D[5]->draw();
    D[6]->draw();
    D[7]->draw();
    D[8]->draw();
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

void Oopdastaan::createDesks()
{
    //std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    D[0] = new desk(100, 450);
    D[1] = new desk(780, 450);
    D[2] = new desk(290, 350);
    D[3] = new desk(590, 350);
    D[4] = new desk(50, 250);
    D[5] = new desk(830, 250);
    D[6] = new desk(280, 150);
    D[7] = new desk(600, 150);
    D[8] = new desk(440,25);
    // cout<<d8->returnCoordinates();
}
void Oopdastaan :: createStudents(){
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