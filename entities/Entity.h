//
// Created by Andrea on 2/3/2020.
//

#ifndef VROOMVROOM_ENTITY_H
#define VROOMVROOM_ENTITY_H

#ifndef WINDOWS_H
#define WINDOWS_H
#include <windows.h>
#endif

enum EntityType {
    nail,
    tank,
    car
};


class Entity {
public:
   // virtual ~Entity() = 0;
    virtual void updateBox();
    virtual void move() = 0;
    virtual void collision() = 0;
    virtual const char *getArt() const = 0;
    virtual COORD getPosition() const = 0;
    virtual COORD getSize() const;

    int getId() const;
    int getType() const;
    SMALL_RECT getBox() const;

protected:
    int type;
    int id;
    int score;              //how it affects score upon collision
    int fuel;               //how it affects fuel upon collision

    float spawnRate;        //how often the Entity should spawn
    const char* pArt;       //pointer to art array
    COORD size;
    COORD position;
    SMALL_RECT box; //TODO add a box mechanism

    Entity(COORD position, int score, int fuel, COORD size);


};


#endif //VROOMVROOM_ENTITY_H
