#ifndef BOOM_H
#define BOOM_H

#include "fallingobjects.hpp"
#include "../cat/cat.hpp"

class Boom : public FallingObjects{
private:
    int color;

public:
    Boom(int x, int y, int r = 20, int s = 8 + rand() % 10, int c = LIGHTGRAY);

    void draw() const override;
    void undraw() const override;
    void fall(int maxHeight);
    bool hit(Cat* cat);
    void effect(Cat* cat) override;
};

#endif
