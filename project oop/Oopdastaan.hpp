#include<SDL.h>
//#include "pigeon.hpp"
//#include "bee.hpp"
//#include "butterfly.hpp"
#include <SDL_image.h>
#include "Classmember.hpp"
#include "faculty.hpp"
#include "students.hpp"
#include "desk.hpp"
#include<vector>
#include<list>
using namespace std;

class Oopdastaan{
/*    // In the solution you have to create vectors of pigeons, eggs, and nests    
    vector<Pigeon*> pigeons;
    vector <bee*> bees;
    vector<butterfly*> butterflies;
    */
    desk **D = new desk*[9];      //container of desks
    Classmember **C = new Classmember*[9];      //container of classmembers
   //students* s9;

    public:

    void drawObjects(); 
    void createStudents();
    SDL_Rect Collision(students*, SDL_Keycode);     //returns the desk of collision
    void createDesks();

    ~Oopdastaan();
    
};