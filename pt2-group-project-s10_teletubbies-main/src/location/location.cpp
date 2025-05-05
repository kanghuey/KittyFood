#include "location.hpp"

Location::Location(int x, int y) : x(x), y(y){}

int Location::getX() const{
    return x;
}

void Location::setX(int x){
    this->x = x;
}

int Location::getY() const{
    return y;
}

void Location::setY(int y){
    this->y = y;
}

void Location::setLocation(int x, int y){
    this->x = x;
    this->y = y;
}
