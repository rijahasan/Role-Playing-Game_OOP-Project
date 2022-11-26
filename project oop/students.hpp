#include <SDL.h>
#include "drawing.hpp"
#include "Classmember.hpp"
#pragma once
using namespace std;


class students : public Classmember{

    public:
    students();
    SDL_Rect getter() const;
    students(SDL_Rect, SDL_Rect, int, int);
    students(int, int);     //constructor overloading, the srcRect for main is only one defined
    bool ismaincharacter=false;         //checks if the created is main character
    void draw();
    ~students();
    // void addinteraction(SDL_Rect&, SDL_Rect&);


};
