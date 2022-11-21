#include<SDL.h>
#include "drawing.hpp"
#include "Classmember.hpp"

class faculty : public Classmember {

    public:
    void draw();
    faculty();
    faculty(int, int);
    ~faculty();

};
 