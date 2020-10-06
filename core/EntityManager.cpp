//
// Created by Andrea on 2/4/2020.
//

#include "EntityManager.h"

#include "Nail.h"
#include "../PlayerCar.h"
#include "globals.h"

extern PlayerCar player;

EntityManager::EntityManager() {
    entityIter = entityList.begin();
}

void EntityManager::spawnEntity(EntityType type, COORD position) {
    switch(type) {
        case nail:
            entityList.push_back(new Nail(position));
            break;
    }
}

void EntityManager::cullInvisible() {
    for (entityIter = entityList.begin(); entityIter != entityList.end(); ++entityIter) {
        if((*entityIter)->getPosition().X < LEFT_BOUND || (*entityIter)->getPosition().X > RIGHT_BOUND &&
        (*entityIter)->getPosition().Y > LOWER_BOUND || (*entityIter)->getPosition().Y < UPPER_BOUND) {
            delete *entityIter;
            entityList.erase(entityIter);
        }
    }
}

void EntityManager::updateEntities() {
    for (entityIter = entityList.begin(); entityIter != entityList.end(); ++entityIter) {
        (*entityIter)->move();
        (*entityIter)->updateBox();
    }
}

void EntityManager::handleCollisions() {
    for (entityIter = entityList.begin(); entityIter != entityList.end(); ++entityIter) {
        if ((*entityIter)->getBox().Bottom < player.box.Top ||(*entityIter)->getBox().Top > player.box.Bottom &&
        (*entityIter)->getBox().Right > player.box.Left ||(*entityIter)->getBox().Left < player.box.Right) {
            (*entityIter)->collision();
        }
    }
}



