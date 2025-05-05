#include <graphics.h>
#include "food.hpp"
#include "../cat/cat.hpp"

Food::Food(int x, int y, int r, int s, int c) : FallingObjects(x, y, r, s), color(c){}

void Food::draw() const{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(location->getX(), location->getY(), radius, radius);
}

void Food::undraw() const{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(location->getX(), location->getY(), radius, radius);
}

void Food::fall(int maxHeight){
    FallingObjects::fall(maxHeight);
}

bool Food::hit(Cat* cat){
    return FallingObjects::hit(cat);
}

void Food::effect(Cat* cat){
    if (hit(cat)){
        cat->addScore(1);
        undraw();
    }
}

