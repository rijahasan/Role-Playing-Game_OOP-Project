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
   desk** D = new desk*[9];     //9 desks in class
   faculty* f1;
   students* s1;
   students* s2;
   students* s3;
   students* s4;
   students* s5;
   students* s6;
   students* s7;
   students* s8;
   //students* s9;

    public:

    void drawObjects(); 
    void createStudents();
    void createDesks();

    ~Oopdastaan();
    
};