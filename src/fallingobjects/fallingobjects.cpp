#include <graphics.h>
#include <cstdlib>
#include "fallingobjects.hpp"
#include "../cat/cat.hpp"

FallingObjects::FallingObjects(int x, int y, int r, int s) : radius(r), speed(s){
    location = new Location(x, y);
}

FallingObjects::~FallingObjects(){
    delete location;
}

void FallingObjects::setLocation(int x, int y){
    location->setLocation(x, y);
}

Location FallingObjects::getLocation() const{
    return *location;
}

void FallingObjects::fall(int maxHeight){
    if(location->getY() < maxHeight + 100){
        undraw();
        setLocation(location->getX(), location->getY() + speed);
        draw();
    }
}

bool FallingObjects::hit(Cat* cat) const{
    int dx = location->getX() - cat->getX();
    int dy = location->getY() - cat->getY();
    int distanceSq = dx * dx + dy * dy;

    int combinedRadius = radius + cat->getRadius();
    int combinedRadiusSq = combinedRadius * combinedRadius;

    return distanceSq <= combinedRadiusSq;
}