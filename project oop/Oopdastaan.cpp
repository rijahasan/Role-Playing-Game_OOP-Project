#include <iostream>
#include "Oopdastaan.hpp"
using namespace std;


void Oopdastaan::drawObjects()
{
    for (auto next : desks)
        next->draw();

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
	desks.push_back(new desk(100, 450));
	desks.push_back(new desk(780, 450));
	desks.push_back(new desk(290, 350));
	desks.push_back(new desk(590, 350));
	desks.push_back(new desk(50, 250));
	desks.push_back(new desk(830, 250));
	desks.push_back(new desk(280, 150));
	desks.push_back(new desk(600, 150));
	desks.push_back(new desk(440, 25));
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

bool Oopdastaan ::  Collision(students* mainStudent, SDL_Keycode key){
    SDL_Rect stud = mainStudent->getter();
    for (auto next : desks)
    {
		SDL_Rect nextdesk = next->getter();

		if (key == SDLK_UP) //when up pressed
    {
        if ((stud.x < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w) > nextdesk.x) and ((stud.y + stud.h)-7 > nextdesk.y) and (stud.y-7 < (nextdesk.y + nextdesk.h)))
            return true;
    }
    else if (key == SDLK_DOWN) //when down key pressed
    {
        if ((stud.x < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w) > nextdesk.x) and ((stud.y + stud.h)+7 > nextdesk.y) and (stud.y+7 < (nextdesk.y + nextdesk.h)))
            return true;
    }
    else if (key == SDLK_RIGHT) //when right key pressed
    {
        if ((stud.x+7 < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w)+7 > nextdesk.x) and ((stud.y + stud.h) > nextdesk.y) and (stud.y < (nextdesk.y + nextdesk.h)))
            return true;
    }
    else if (key == SDLK_LEFT) //when left key pressed
    {
        if ((stud.x-7 < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w)-7 > nextdesk.x) and ((stud.y + stud.h) > nextdesk.y) and (stud.y < (nextdesk.y + nextdesk.h)))
            return true;
    }
	}
return false;
}
