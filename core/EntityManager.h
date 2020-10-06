//
// Created by Andrea on 2/4/2020.
//

#ifndef VROOMVROOM_ENTITYMANAGER_H
#define VROOMVROOM_ENTITYMANAGER_H

#include <list>
#include "Entity.h"

class EntityManager {
public:
    EntityManager();
    void spawnEntity(EntityType type, COORD position);
    void cullInvisible();
    void updateEntities();
    void delete_entity(int id);

    void handleCollisions();


    std::list<Entity*> entityList;
    std::list<Entity*>::iterator entityIter;

private:
};


#endif //VROOMVROOM_ENTITYMANAGER_H
