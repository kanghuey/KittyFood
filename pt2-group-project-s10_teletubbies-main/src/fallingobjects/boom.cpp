#include <graphics.h>
#include "boom.hpp"
#include "../cat/cat.hpp"

Boom::Boom(int x, int y, int r, int s, int c) : FallingObjects(x, y, r, s), color(c){}

void Boom::draw() const{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(location->getX(), location->getY(), radius, radius);
}

void Boom::undraw() const{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(location->getX(), location->getY(), radius, radius);
}

void Boom::fall(int maxHeight){
    FallingObjects::fall(maxHeight);
}

bool Boom::hit(Cat* cat){
    return FallingObjects::hit(cat);
}

void Boom::effect(Cat* cat){
    if (hit(cat)){
        cat->addLife(-1);
        undraw();
    }
}
