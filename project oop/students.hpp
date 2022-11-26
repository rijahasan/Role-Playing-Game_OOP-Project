#include <SDL.h>
#include "drawing.hpp"
#include "Classmember.hpp"
#pragma once
using namespace std;


class students : public Classmember{

    public:
    students();
    SDL_Rect getter() const;
    students(int, int);
    ~students();
    void addinteraction(SDL_Rect, SDL_Rect);


};
