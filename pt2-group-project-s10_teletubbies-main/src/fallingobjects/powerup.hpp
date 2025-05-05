#ifndef POWERUP_H
#define POWERUP_H

#include "fallingobjects.hpp"
#include "../cat/cat.hpp"

class Powerup : public FallingObjects{
private:
    int type;

public:
    Powerup(int x, int y, int r = 20, int s = 8 + rand() % 10, int t = 0);

    void draw() const override;
    void undraw() const override;
    void fall(int maxHeight);
    bool hit(Cat* cat);
    void effect(Cat* cat) override;
};

#endif
