#ifndef FALLINGOBJECTS_H
#define FALLINGOBJECTS_H

#include "../location/location.hpp"
#include "../cat/cat.hpp"

class FallingObjects{
protected:
    int radius;
    int speed;
    Location* location;

public:
    FallingObjects(int x = 0, int y = 0, int r = 0, int speed = 0);
    virtual ~FallingObjects();

    void setLocation(int x, int y);
    Location getLocation() const;

    virtual void draw() const = 0;
    virtual void undraw() const = 0;
    virtual void fall(int maxHeight);
    virtual bool hit(Cat* cat) const;
    virtual void effect(Cat* cat) = 0;
};

#endif
