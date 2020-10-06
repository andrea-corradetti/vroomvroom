//
// Created by Andrea on 1/25/2020.
//

#ifndef VROOMVROOM_PLAYERCAR_H
#define VROOMVROOM_PLAYERCAR_H

#ifndef WINDOWS_H
#define WINDOWS_H
#include <windows.h>
#endif

#define CAR_WIDTH 2
#define CAR_LENGTH 3

class PlayerCar {

public:
    PlayerCar(COORD position);

    COORD position;
    COORD size;
    SMALL_RECT box;

    static char art[6];

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void updatePlayer(CHAR_INFO consoleBuffer[]);
    void updateBox();

};


#endif //VROOM;VROOM_PLAYERCAR_H
