#include <graphics.h>
#include "cat.hpp"

Cat::Cat(int _x, int _y, int _radius, int _speed, int _maxLeftEdge, int _maxRightEdge, Score* _score, Life* _life)
    : x(_x), y(_y), radius(_radius), speed(_speed), maxLeftEdge(_maxLeftEdge), maxRightEdge(_maxRightEdge), score(_score), life(_life){}

void Cat::draw() const{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, radius, radius);
}

void Cat::undraw() const{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x, y, radius, radius);
}

void Cat::move(int dx){
    undraw();
    x += dx;
    if (x - radius < maxLeftEdge){
        x = maxLeftEdge + radius;
    }
    if (x + radius > maxRightEdge){
        x = maxRightEdge - radius;
    }
    draw();
}

void Cat::addScore(int s){
    score->undraw();
    score->add(s);
    score->draw();
}

void Cat::addLife(int l){
    life->undraw();
    life->add(l);
    if (life->getLife() < 0){
        life->setLife(0); //Ensure life doesn't go below 0
    }
    life->draw();
}

void Cat::addSpeed(int spd){
    speed += spd;
    if (speed > 50){
        speed = 50; //Ensure speed doesn't exceed maxSpeed
    }
}
