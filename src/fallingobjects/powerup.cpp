#include <graphics.h>
#include "powerup.hpp"
#include "../cat/cat.hpp"

Powerup::Powerup(int x, int y, int r, int s, int t) : FallingObjects(x, y, r, s), type(t){}

void Powerup::draw() const{
    int color;
    if (type == 0){
        color = RED;
    } else if (type == 1){
        color = BLUE;
    }
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(location->getX(), location->getY(), radius, radius);
}

void Powerup::undraw() const{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(location->getX(), location->getY(), radius, radius);
}

void Powerup::fall(int maxHeight){
    FallingObjects::fall(maxHeight);
}

bool Powerup::hit(Cat* cat){
    return FallingObjects::hit(cat);
}

void Powerup::effect(Cat* cat){
    if (hit(cat)){
        if (type == 0){
            cat->addLife(1);
        } else if (type == 1){
            cat->addSpeed(1);
        }
        undraw();
    }
}