#include<SDL.h>
#include <iostream>
#include "drawing.hpp"
#include "Classmember.hpp"

class faculty : public Classmember {

    public:
    faculty();
    faculty(int, int);
    ~faculty();
    void draw();
    bool viva();
};
 