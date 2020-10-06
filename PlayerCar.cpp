//
// Created by Andrea on 1/25/2020.
//


#include "PlayerCar.h"
#include "core/Screen.h"


char PlayerCar::art[] = {
'@', '@',
'I', 'I',
'@', '@'
};

//todo fix bounds
void PlayerCar::moveLeft() {
    if (position.X - 1 >= 0)
        position.X -= 1;
}

void PlayerCar::moveRight() {
    if (position.X + 1 + size.X < 10)
        position.X += 1;
}

void PlayerCar::moveUp() {
    if (position.Y - 1 >= 0)
        position.Y -= 1;
}

void PlayerCar::moveDown() {
    if (position.Y + 1 + size.Y < 10)
        position.Y += 1;
}


void PlayerCar::updatePlayer(CHAR_INFO consoleBuffer[]) {
    for (int y = 0; y <= CAR_LENGTH; y++) {
        for (int x = 0; x <= CAR_WIDTH; x++) {
            consoleBuffer[position.X + x + (position.Y + y) * WIDTH].Char.UnicodeChar = art[x + y * CAR_WIDTH];
        }
    }
}

void PlayerCar::updateBox() {
    box.Top = position.Y;
    box.Left = position.X;
    box.Bottom = position.Y + size.Y;
    box.Right = position.X + size.X;
}

PlayerCar::PlayerCar(COORD position) {
    this->size = {CAR_WIDTH, CAR_LENGTH};
    this->position = position;
}





