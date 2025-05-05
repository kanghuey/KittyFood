#include <graphics.h>
#include "life.hpp"

Life::Life(int _x, int _y, int _size, int _color): x(_x), y(_y), size(_size), color(_color), life(2){}

void Life::draw() const{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);

    for (int i = 0; i < life; ++i){
        int left_circle_x = x - size / 4 - i * (size + 10);
        int right_circle_x = x + size / 4 - i * (size + 10);
        int circle_y = y;
        int radius = size / 4;
        circle(left_circle_x, circle_y, radius);
        floodfill(left_circle_x, circle_y, color);
        circle(right_circle_x, circle_y, radius);
        floodfill(right_circle_x, circle_y, color);
        int arr3[] ={left_circle_x - radius / 2, circle_y + radius / 2, right_circle_x + radius / 2, circle_y + radius / 2, x - i * (size + 10), y + size / 2, left_circle_x - radius / 2, circle_y + radius / 2};
        fillpoly(4, arr3);
    }
}

void Life::undraw() const{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    for (int i = 0; i < 3; ++i){ // Clear all potential hearts
        int left_circle_x = x - size / 4 - i * (size + 10);
        int right_circle_x = x + size / 4 - i * (size + 10);
        int circle_y = y;
        int radius = size / 4;
        circle(left_circle_x, circle_y, radius);
        floodfill(left_circle_x, circle_y, BLACK);
        circle(right_circle_x, circle_y, radius);
        floodfill(right_circle_x, circle_y, BLACK);
        int arr3[] ={left_circle_x - radius / 2, circle_y + radius / 2, right_circle_x + radius / 2, circle_y + radius / 2, x - i * (size + 10), y + size / 2, left_circle_x - radius / 2, circle_y + radius / 2};
        fillpoly(4, arr3);
    }
}

void Life::add(int l){
    life += l;
    if (life > 2){
        life = 2;   //Ensure life doesn't exceed max value
    }
}

void Life::setLife(int l){
    life = l;
}

int Life::getLife() const{
    return life;
}
