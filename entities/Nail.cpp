//
// Created by Andrea on 2/3/2020.
//

#include "Nail.h"
#include "globals.h"

const EntityType type = nail;
const char Nail::art[] = {'i'};

Nail::Nail(COORD position, int score, int fuel) : Entity(position, score, fuel, {NAIL_WIDTH, NAIL_HEIGHT}) {
    this->pArt = Nail::art;
}

void Nail::move() {
    this->position.Y += 1;
}

void Nail::collision() {
    score -= this->score;
}

COORD Nail::getSize() const {
    return size;
}

const char *Nail::getArt() const{
    return pArt;
}

COORD Nail::getPosition() const {
    return position;
}


