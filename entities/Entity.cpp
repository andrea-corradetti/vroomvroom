//
// Created by Andrea on 2/3/2020.
//

#include "Entity.h"

Entity::Entity(COORD position, int score, int fuel, COORD size) : size(size){
    this->position = position;
    this->score = score;
    this->fuel = fuel;
    updateBox();
}

int Entity::getId() const {
    return id;
}

int Entity::getType() const {
    return type;
}

SMALL_RECT Entity::getBox() const {
    return box;
}
void Entity::updateBox() {
    box.Top = position.Y;
    box.Left = position.X;
    box.Bottom = position.Y + size.Y;
    box.Right = position.X + size.X;
}

COORD Entity::getSize() const {
    return size;
}



