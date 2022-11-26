#include <iostream>
#include "Oopdastaan.hpp"
using namespace std;


void Oopdastaan::drawObjects()
{
    for (int i=0;i<9;i++)
        D[i]->draw();
    for (int i=0;i<9;i++)
        C[i]->draw();
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
    D[1] = new desk(440, 25);
	D[2] = new desk(780, 450);
	D[3] = new desk(290, 350);
	D[4] = new desk(590, 350);
	D[5] = new desk(50, 250);
	D[6] = new desk(830, 250);
	D[7] = new desk(280, 150);
	D[8] = new desk(600, 150);
    // cout<<d8->returnCoordinates();
}
void Oopdastaan :: createStudents(){
    C[0] = new faculty(470, 0);
    C[1] = new students(130,490);
    C[2] = new students(810, 490);
    C[3] = new students(320, 390);
    C[4] = new students(620,390);
    C[5] = new students(80, 290);
    C[6] = new students(860, 290);
    C[7] = new students(310, 190);
    C[8] = new students(630, 190);
    //s9 = new students(20, 510);

}

SDL_Rect Oopdastaan ::  Collision(students* mainStudent, SDL_Keycode key){
    SDL_Rect stud = mainStudent->getter();
    for (int i=0;i<9;i++)
    {
		SDL_Rect nextdesk = D[i]->getter();

		if (key == SDLK_UP) //when up pressed
    {
        if ((stud.x < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w) > nextdesk.x) and ((stud.y + stud.h)-7 > nextdesk.y) and (stud.y-7 < (nextdesk.y + nextdesk.h)))
            return nextdesk;
    }
    else if (key == SDLK_DOWN) //when down key pressed
    {
        if ((stud.x < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w) > nextdesk.x) and ((stud.y + stud.h)+7 > nextdesk.y) and (stud.y+7 < (nextdesk.y + nextdesk.h)))
            return nextdesk;
    }
    else if (key == SDLK_RIGHT) //when right key pressed
    {
        if ((stud.x+7 < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w)+7 > nextdesk.x) and ((stud.y + stud.h) > nextdesk.y) and (stud.y < (nextdesk.y + nextdesk.h)))
            return nextdesk;
    }
    else if (key == SDLK_LEFT) //when left key pressed
    {
        if ((stud.x-7 < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w)-7 > nextdesk.x) and ((stud.y + stud.h) > nextdesk.y) and (stud.y < (nextdesk.y + nextdesk.h)))
            return nextdesk;
    }
	}
return {0,0,0,0};
}

Oopdastaan:: ~Oopdastaan()
{
    for (int i=0;i<9;i++)
        delete D[i];
    delete [] D;
    for (int i=0;i<9;i++)
        delete C[i];
    delete [] C;
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

