#ifndef LIFE_H
#define LIFE_H

class Life
{
private:
    int x, y;
    int size;
    int color;
    int life;

public:
    Life(int _x, int _y, int _size, int _color = LIGHTRED);
    void draw() const;
    void undraw() const;
    void add(int l);
    void setLife(int l);
    int getLife() const;
};

#endif