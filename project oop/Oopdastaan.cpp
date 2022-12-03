#include <iostream>
#include "Oopdastaan.hpp"
using namespace std;


void Oopdastaan::drawObjects()      
{
    C[0]->draw();       //draws faculty first, because the orientation is different
    interacted[0]=false; 
    for (int i=0;i<10;i++)
        D[i]->draw();       //window is taken as a kind of desk
    for (int i=1;i<9;i++){
        C[i]->draw();
        interacted[i]=false;        //interaction has not happened
    }
}

void Oopdastaan::createDesks()
{
	D[1] = new desk(100, 450);      //1     the index of desk and student are same, association
    D[0] = new desk(440, 45);       //F
	D[2] = new desk(780, 450);      //2
	D[3] = new desk(290, 350);      //3
	D[4] = new desk(590, 350);      //4
	D[5] = new desk(50, 250);      //5
	D[6] = new desk(830, 250);      //6
	D[7] = new desk(260, 165);      //7
	D[8] = new desk(620, 165);      //8
	D[9] = new desk({42, 1550, 52, 356}, {980,65,20,137});      //9     //window is a type of  desk 
    // cout<<d8->returnCoordinates();
}
void Oopdastaan :: createStudents(){
    C[0] = new faculty(470, 20);      
    C[1] = new students({639, 480, 81, 179}, {936, 480, 79, 179}, 130,515);       //hammad
    C[2] = new students({956, 1507, 115, 224}, {1251, 1507, 115, 224}, 810, 515);      //flash
    C[3] = new students({56, 1563, 137, 168}, {351, 1563, 137, 168}, 320, 415);      //sidra
    C[4] = new students({539, 1280, 112, 191}, {834, 1280, 114, 191}, 620,415); //shaheer
    C[5] = new students({79, 983, 70, 169}, {373, 983, 70, 168}, 80, 315); //zain
    C[6] = new students({632, 968, 91, 188}, {927, 968, 92, 188}, 860, 315);
    C[7] = new students({67,720, 93, 180},{363, 720, 91, 180}, 290, 240);       //hamza
    C[8] = new students({650,726,92,157}, {956, 726, 92, 157}, 650, 240);      //pink gal
    C[9] = new RahimBhai();      //rahimbhai only has interactions
    
    //Feeding interactions into the classmember objects 
    C[0]->addinteraction({2021, 29, 752, 134}, {560, 15, 260, 46}); //faculty
    C[0]->addinteraction({2898, 29, 752, 134}, {560, 15, 260, 46});
    C[0]->addinteraction({2021, 231, 752, 134}, {560, 15, 260, 46});
    C[0]->addinteraction({2898, 231, 752, 134}, {560, 15, 260, 46});
    C[0]->addinteraction({2021,431,752,134}, {560, 15, 260, 46});
    C[0]->addinteraction({2898,433,752,134}, {560, 15, 260, 46});
    C[0]->addinteraction({2021,631,752,134}, {560, 15, 260, 46});
    C[0]->addinteraction({2898,631,752,134}, {560, 15, 260, 46});
    C[0]->addinteraction({2030,840,734,116}, {560, 15, 260, 46});
    C[0]->addinteraction({2021,1032,752,133}, {560, 15, 260, 46});
    C[0]->addinteraction({2898,1031,752,134}, {560, 15, 260, 46});
    C[0]->addinteraction({2021,1232,752,134}, {560, 15, 260, 46});
    C[0]->addinteraction({2021,1447,752,134}, {560, 15, 260, 46});
    C[0]->addinteraction({2021,1731,752,134}, {560, 15, 260, 46});
    C[0]->addinteraction({2898,1717,752,134}, {560, 15, 260, 46});

    C[1]->addinteraction({21, 3032, 752, 133}, {50, 400, 260, 46});
    C[1]->addinteraction({898, 3031, 752, 133} , {40, 400, 260, 46});
    C[1]->addinteraction({21, 3232, 751, 133} , {50, 400, 260, 46});
    C[1]->addinteraction({898,3231, 752,133} , {50, 400, 260, 46});
    C[1]->addinteraction({21,3432,752,134}, {50, 400, 260, 46});    

    C[2]->addinteraction({21,231,752,134}, {750, 400, 260, 46});
    C[2]->addinteraction({898,231,752,134}, {750, 400, 260, 46});
    C[2]->addinteraction({21,431,752,133}, {750, 400, 260, 46});
    C[2]->addinteraction({892,429,751,134}, {750, 400, 260, 46});
    
    C[3]->addinteraction({21, 3632, 752, 134},{300, 305, 260, 46}) ;//sidra
    C[3]->addinteraction({898, 3631, 752, 133},{300, 305, 260, 46}) ;
    C[3]->addinteraction({21, 3833, 752, 133},{300, 305, 260, 46}) ;

    C[4]->addinteraction({21, 4231, 752, 134}, {590, 310, 260, 46}); //shaheer

    C[5]->addinteraction({21, 4431, 752, 133}, {2, 200, 260, 46}); //alizain
    C[5]->addinteraction({898, 4431, 752, 133}, {2, 200, 260, 46});
    C[5]->addinteraction({21, 4631, 752, 134}, {2, 200, 260, 46});
    C[5]->addinteraction({898, 4631, 752, 134}, {2, 200, 260, 46});

    C[6]->addinteraction({21,4832,752,133}, {760, 200, 260, 46});   //eman
    C[6]->addinteraction({898,4831,752,134}, {760, 200, 260, 46});
    C[6]->addinteraction({21,5032,752,133}, {760, 200, 260, 46});
    C[6]->addinteraction({898,5036,747,128}, {760, 200, 260, 46});
    C[6]->addinteraction({898,5231,752,133}, {760, 200, 260, 46});
    C[6]->addinteraction({21,5432,752,134}, {760, 200, 260, 46});
    C[6]->addinteraction({898,5431,752,133}, {760, 200, 260, 46});
    C[6]->addinteraction({21,5632,752,134}, {760, 200, 260, 46});
    C[6]->addinteraction({898,5631,752,133}, {760, 200, 260, 46});
    C[6]->addinteraction({21,5833,752,133}, {760, 200, 260, 46});

    C[7]->addinteraction({21,1032,752,133}, {250, 110, 260, 46});   //hamza
    C[7]->addinteraction({898,1039,752,129}, {250, 110, 260, 46});
    C[7]->addinteraction({21,1232,752,133}, {250, 110, 260, 46});
    C[7]->addinteraction({898,1231,752,133}, {250, 110, 260, 46});
    C[7]->addinteraction({21,1432,752,134}, {250, 110, 260, 46});

    C[8]->addinteraction({21,2029,752,134}, {630, 110, 260, 46}); //burhan
    C[8]->addinteraction({898,2029,752,134}, {630, 110, 260, 46});
    C[8]->addinteraction({21, 2231, 752,134}, {630, 110, 260, 46});
    C[8]->addinteraction({898,2231,752,134}, {630, 110, 260, 46});
    C[8]->addinteraction({21,2436,752,128}, {630, 110, 260, 46});

    C[9]->addinteraction({21,631,752,134}, {698, 99, 260, 46});
    C[9]->addinteraction({898,631,752,134}, {698, 99, 260, 46});
    C[9]->addinteraction({21,832,752,133}, {698, 99, 260, 46});
    C[9]->addinteraction({898,827,752,134}, {698, 99, 260, 46});

}

SDL_Rect Oopdastaan ::  Collision(students* mainStudent, SDL_Keycode key){      //function to detect collision, takes main student (for position) and pressed key as parameters 
    SDL_Rect stud = mainStudent->getter();      //gets the mains students srcmover 
    for (int i=0;i<10;i++)  //inetrated over all the desks
    {
		SDL_Rect nextdesk = D[i]->getter();

		if (key == SDLK_UP) //when up pressed
    {
        if ((stud.x < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w) > nextdesk.x) and ((stud.y + stud.h)-7 > nextdesk.y) and (stud.y-7 < (nextdesk.y + nextdesk.h))){     //checks for collision
            if (i==0)
                isfaculty=true;
            return nextdesk;}       //returns the desk colllided
    }
    else if (key == SDLK_DOWN) //when down key pressed
    {
        if ((stud.x < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w) > nextdesk.x) and ((stud.y + stud.h)+7 > nextdesk.y) and (stud.y+7 < (nextdesk.y + nextdesk.h))){
            if (i==0)       //if collision happens with the instructor 
                isfaculty=true;
            return nextdesk;
        }
    }
    else if (key == SDLK_RIGHT) //when right key pressed
    {
        if ((stud.x+7 < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w)+7 > nextdesk.x) and ((stud.y + stud.h) > nextdesk.y) and (stud.y < (nextdesk.y + nextdesk.h))){
            if (i==0)
                isfaculty=true;
            return nextdesk;
        }
    }
    else if (key == SDLK_LEFT) //when left key pressed
    {
        if ((stud.x-7 < (nextdesk.x + nextdesk.w)) and ((stud.x+stud.w)-7 > nextdesk.x) and ((stud.y + stud.h) > nextdesk.y) and (stud.y < (nextdesk.y + nextdesk.h))){
            if (i==0)       
                isfaculty=true;
            return nextdesk;
        }
    }
	}
    return {0,0,0,0};       //if no desk is collided a zero SDL_Rect is returned which is check in the game function to detect no collision
}

bool Oopdastaan :: turnstudentAtDesk(SDL_Rect dsk){ //this function turns the student at a particular desk whne the user presses x near it
    int i=0;
    for (;i<9;i++){
        SDL_Rect nextdesk=D[i]->getter();
        if (dsk.x==nextdesk.x && dsk.y==nextdesk.y && dsk.w==nextdesk.w && dsk.h==nextdesk.h){
            C[i]->turned=true;
            break;}   
            }
    if (i==0){
        isfaculty=true;
    }
    if (interacted[i]==true){
        C[i]->turned=false;
        return false;       //if the student is already interacted with, then returns false
    }
    else 
        nextinteraction=i;
    return true;
}

bool Oopdastaan :: interact(bool Cont){     //checks whether to move on to next statement
    if (!Cont){
        interacted[nextinteraction] = C[nextinteraction]->drawnextinteraction();        //if the textboxes are empty then interaction complete and true is returned
        if (nextinteraction==0 && C[nextinteraction]->viva()==true)     //checks if questions have started
            VivaStarted=true;
    }
    else
        C[nextinteraction]->drawinteraction();
    if (interacted[nextinteraction])
        return true;        //interaction completed
    return false;

}
bool Oopdastaan ::  Isfaculty(){        //check if the interaction with faculty has started or not
    return isfaculty;
}

bool Oopdastaan ::  getvivastatus(){        //checks if the viva has started or not  
    return VivaStarted;
}

int Oopdastaan ::  facultyinteractionnum(){     //checks the textbox number while interacting with faculty (important to detect to alert the player that vica and timer is starting)
    return C[0]->I.getcount();
}

int Oopdastaan :: getquestionnum(){     //return the current question number the viva is on
    return C[nextinteraction]->I.questionnum();
    }

bool Oopdastaan :: checkans(int a, SDL_Keycode key){        //checks if the answer for a specific question is correct or not
    switch (a){
        case 1:
            if (key==SDLK_y)
                return true;
            else
                return false;
        break;
        case 2:
            if (key==SDLK_y)
                return true;
            else
                return false;
        break;
        case 3:
            if (key==SDLK_n)
                return true;
            else
                return false;
        break;
        case 4:
            if (key==SDLK_y)
                return true;
            else
                return false;
        break;
        default:
            cout<<"press a valid key (y or n)"<<endl;      //if an invalid key is pressed during viva 
    }
}

bool Oopdastaan :: interactedstatus (int a){        //returns interacted status of a classmember at index a
    return interacted[a];
}

Oopdastaan:: ~Oopdastaan()      //destructor for oopdastan, releases all memory for the dynamically created objects
{
    for (int i=0;i<10;i++)
        delete D[i];
    delete [] D;
    for (int i=0;i<10;i++)
        delete C[i];
    delete [] C;
    delete [] interacted;
}

