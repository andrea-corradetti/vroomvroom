//
// Created by Andrea on 2/3/2020.
//

#ifndef VROOMVROOM_NAIL_H
#define VROOMVROOM_NAIL_H

#define NAIL_WIDTH 1
#define NAIL_HEIGHT 1

#include "Entity.h"

class Nail: public Entity {
public:
    //todo fix size inheritance
    static const char art[1];
    static const EntityType type;

    Nail(COORD position, int score = -5, int fuel = - 10);
    void move();
    void collision();

    const char *getArt() const;
    COORD getSize() const;
    COORD getPosition() const;
};


#endif //VROOMVROOM_NAIL_H
