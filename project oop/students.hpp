#include<SDL.h>
#include "drawing.hpp"
#include "Classmember.hpp"
#pragma once

class students : public Classmember{

    public:
    void draw();
    students();
    students(int, int);
    ~students();

};
