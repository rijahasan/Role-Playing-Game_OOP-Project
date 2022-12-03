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
    desk **D = new desk*[10];      //container of desks, dynamically creates an array of desk pointers
    Classmember **C = new Classmember*[10];      //similar container of classmembers
    bool* interacted= new bool[9];
    int nextinteraction;        //checks the index for next interaction
    bool isfaculty=false;      //checks if Gulab is interacting with faculty
    bool VivaStarted=false;     //checks if the viva has started
    public:
    void drawObjects();         
    void createStudents();
    SDL_Rect Collision(students*, SDL_Keycode);     //returns the desk of collision
    void createDesks();
    bool interact(bool);        //calls draw interactions functions to interact
    bool turnstudentAtDesk(SDL_Rect);   //takes the desk of collision and returns if the classmembera at that desk has interacted with or not 
    bool Isfaculty();      //returns the faculty status
    bool getvivastatus();       //returns the viva status
    int getquestionnum();       //returns the current question number from the faculty 
    bool checkans(int,SDL_Keycode); //checks if the answer is correct, returns true if it is , false if not
    int facultyinteractionnum();        //returns the current textbox number of the interaction with faculty (important to alert the player that viva is starting)
    bool interactedstatus (int);    //returns true if the classmember has been interacted with
    ~Oopdastaan();
};

