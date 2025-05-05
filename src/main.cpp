#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include "../src/cat/cat.hpp"
#include "../src/boards/life.hpp"
#include "../src/boards/score.hpp"
#include "../src/fallingobjects/boom.hpp"
#include "../src/fallingobjects/food.hpp"
#include "../src/fallingobjects/powerup.hpp"
#include "../src/game/game.hpp"
#include "../src/game/align.hpp"

#define MAX_OBJECTS 6

//Spawn random objects
void spawnObjects(FallingObjects*& obj, int width){
    int type = rand() % 10;
    if (type < 5){
        obj = new Food(rand() % width, 0);
    } else if (type < 8){
        obj = new Boom(rand() % width, 0);
    } else{
        int randomType = rand() % 2;
        obj = new Powerup(rand() % width, 0, 20, 12 + rand() % 15, randomType);
    }
}

int main(){
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth, screenHeight, "", -3, -3);

    srand(time(NULL));

    //Create Game and Score and Life objects
    Game game;
    Score score;
    Life life(screenWidth - 60, 30, 40, LIGHTRED);

    //Create Cat object
    Cat cat(screenWidth / 2, screenHeight - 30, 30, 20, 0, screenWidth, &score, &life);

    //Create array of falling objects
    FallingObjects* objects[MAX_OBJECTS];

    //Spawn a set of random objects
    for (int i = 0; i < MAX_OBJECTS; i++){
        spawnObjects(objects[i], screenWidth);
    }

    char ch = 0;
    while (ch != 27){   //While Esc key is not pressed
        if (kbhit()){
            ch = getch();
        }

        cleardevice();

        if (ch == 75){  //Left arrow key pressed
            cat.move(-cat.getSpeed());
        } else if (ch == 77){   //Right arrow key pressed
            cat.move(cat.getSpeed());
        }

        for (int i = 0; i < MAX_OBJECTS; i++){
            objects[i]->fall(screenHeight);

            if (objects[i]->hit(&cat)){ //When object hits cat
                objects[i]->effect(&cat); //Apply effect on cat
                delete objects[i];
                spawnObjects(objects[i], screenWidth);
            } else if (objects[i]->getLocation().getY() > screenHeight + 100){ //Delete and respawn objects when fall out of screen
                delete objects[i];
                spawnObjects(objects[i], screenWidth);
            }
        }

        //When life reaches 0, game end
        if (life.getLife() == 0){
            game.end();
            system("pause");
            return 0;
        }

        //When score reaches 10, game win
        if (score.getScore() == 10){
            game.win();
            system("pause");
            return 0;
        }

        cat.draw();
        life.draw();
        score.draw();

        delay(50);
    }

    closegraph();
    return 0;
}
