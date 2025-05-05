#ifndef FOOD_H
#define FOOD_H

#include "fallingobjects.hpp"
#include "../cat/cat.hpp"

class Food : public FallingObjects{
private:
    int color;

public:
    Food(int x, int y, int r = 20, int s = 8 + rand() % 10, int c = LIGHTGREEN);

    void draw() const override;
    void undraw() const override;
    void fall(int maxHeight);
    bool hit(Cat* cat);
    void effect(Cat* cat) override;
};

#endif
