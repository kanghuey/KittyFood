#include <graphics.h>
#include "score.hpp"

Score::Score() : score(0){}

void Score::add(int points)
{
    score += points;
}

int Score::getScore()const
{
    return score;
}

void Score::draw() const{
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    outtextxy(10, 10, scoreText);  
}

void Score::undraw() const{
    setcolor(BLACK);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    outtextxy(10, 10, scoreText); 
}

