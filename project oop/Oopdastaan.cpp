#include <iostream>
#include "Oopdastaan.hpp"
using namespace std;


void Oopdastaan::drawObjects()
{
    C[0]->draw();
    for (int i=0;i<9;i++)
        D[i]->draw();
    for (int i=1;i<9;i++)
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
	D[1] = new desk(100, 450);      //1     the index of desk and student are same
    D[0] = new desk(440, 35);       //F
	D[2] = new desk(780, 450);      //2
	D[3] = new desk(290, 350);      //3
	D[4] = new desk(590, 350);      //4
	D[5] = new desk(50, 250);      //5
	D[6] = new desk(830, 250);      //6
	D[7] = new desk(260, 165);      //7
	D[8] = new desk(620, 165);      //8
    // cout<<d8->returnCoordinates();
}
void Oopdastaan :: createStudents(){
    C[0] = new faculty(470, 20);      
    C[1] = new students({639, 480, 81, 179}, {936, 480, 79, 179}, 130,515);       //hammad
    C[2] = new students({956, 1507, 115, 224}, {1251, 1507, 115, 224}, 810, 515);      //flash
    C[3] = new students({56, 1563, 137, 168}, {351, 1563, 137, 168}, 320, 415);      //sidra
    C[4] = new students({539, 1280, 112, 191}, {834, 1280, 114, 191}, 620,415);
    C[5] = new students({79, 983, 70, 169}, {373, 983, 70, 168}, 80, 315);
    C[6] = new students({632, 968, 91, 188}, {927, 968, 92, 188}, 860, 315);
    C[7] = new students({67,720, 93, 180},{363, 720, 91, 180}, 290, 240);       //hamza

    // ({0,0,0,0}, {834, 1280, 114, 191}, 310, 190);       //dude w fanny bag
    C[8] = new students({650,726,92,157}, {956, 726, 92, 157}, 650, 240);      //pink gal
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
void Oopdastaan :: turnstudentAtDesk(SDL_Rect dsk){ //this function turns the student at a particular desk whne the user presses x near it
    for (int i=0;i<9;i++){
        SDL_Rect nextdesk=D[i]->getter();
        if (dsk.x==nextdesk.x && dsk.y==nextdesk.y && dsk.w==nextdesk.w && dsk.h==nextdesk.h){
            C[i]->turned=true;
        }
    }
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

