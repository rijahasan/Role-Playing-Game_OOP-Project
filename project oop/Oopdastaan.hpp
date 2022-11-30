#pragma once
#include<SDL.h>
#include <SDL_image.h>
#include "Classmember.hpp"
#include "faculty.hpp"
#include "students.hpp"
#include "RahimBhai.hpp"
#include "desk.hpp"
#include<vector>
#include<list>
#include<list>
using namespace std;

class Oopdastaan{
/*    // In the solution you have to create vectors of pigeons, eggs, and nests    
    vector<Pigeon*> pigeons;
    vector <bee*> bees;
    vector<butterfly*> butterflies;
    */
    desk **D = new desk*[10];      //container of desks
    Classmember **C = new Classmember*[10];      //container of classmembers
   //students* s9;
    bool* interacted= new bool[9];
    int nextinteraction;
    bool isfaculty=false;
    bool VivaStarted=false;
    public:

    void drawObjects(); 
    void createStudents();
    SDL_Rect Collision(students*, SDL_Keycode);     //returns the desk of collision
    void createDesks();
    bool interact(bool);
    bool turnstudentAtDesk(SDL_Rect);
    bool Isfaculty();
    bool getvivastatus();
    int getquestionnum();
    bool checkans(int,SDL_Keycode); //checks if the answer is correct, returns true if it is , false if not
    int facultyinteractionnum();
    ~Oopdastaan();
};