#ifndef CAT_HPP
#define CAT_HPP

#include <graphics.h>
#include "../boards/life.hpp"
#include "../boards/score.hpp"

class Cat {
private:
    int x, y;
    int radius;
    int speed;
    int maxLeftEdge;
    int maxRightEdge;

    Life *life;
    Score *score;

public:
    Cat(int _x, int _y, int _radius, int _speed, int _maxLeftEdge, int _maxRightEdge, Score* _score, Life* _life);

    void draw() const;
    void undraw() const;
    void move(int dx);

    int getX() const { return x; }
    int getY() const { return y; }
    int getRadius() const { return radius; }
    int getSpeed() const { return speed; }
    void addScore(int s);
    void addLife(int l);
    void addSpeed(int spd);
};

#endif