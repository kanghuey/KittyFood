#include <graphics.h>
#include "game.hpp"
#include "align.hpp"

void Game::end()
{
    setfillstyle(SOLID_FILL, RED);
    setbkcolor(RED);
    setcolor(YELLOW);
    int w = 1000;
    int h = 300;
    int x = Align::center(0, getmaxwidth(), w);
    int y = Align::center(0, getmaxheight(), h);
    bar(x, y, x + w, y + h);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 10);
    char message[] = "Game Over!";
    int tw = textwidth(message);
    int th = textheight(message);

    int tx = Align::center(x, x + w, tw);
    int ty = Align::center(y, y + h, th);

    outtextxy(tx, ty, message);
}

void Game::win()
{
    setfillstyle(SOLID_FILL, GREEN);
    setbkcolor(GREEN);
    setcolor(YELLOW);
    int w = 1000;
    int h = 300;
    int x = Align::center(0, getmaxwidth(), w);
    int y = Align::center(0, getmaxheight(), h);
    bar(x, y, x + w, y + h);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 10);
    char message[] = "Game Win!";
    int tw = textwidth(message);
    int th = textheight(message);

    int tx = Align::center(x, x + w, tw);
    int ty = Align::center(y, y + h, th);

    outtextxy(tx, ty, message);
}