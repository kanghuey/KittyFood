#ifndef SCORE_H
#define SCORE_H

class Score{
private:
    int score;

public:
    Score();
    void add(int points);
    int getScore() const;
    void draw()const;
    void undraw()const;
};
#endif