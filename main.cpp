#include <iostream>

#include "core/Screen.h"
#include "core/Controls.h"
#include "time.h"
#include "core/globals.h"

PlayerCar player({0, 0});
EntityManager manager;
int score = 0;
int fuel = 100;



int main() {


    Screen screen;
    Controls controls;
    bool running = true;

    clock_t last = clock();
    double amountOfTicks = 60.;
    double timePerTick = 1. / amountOfTicks;
    double delta = 0;
            manager.spawnEntity(nail, {2, 2});

    while (running) {
        delta += (last - clock())/ CLOCKS_PER_SEC / timePerTick;                //fixes the game at 60 ticks per second
        last = clock();
        if (delta >= 1) {
            controls.handleInput(player);
            manager.updateEntities();
            screen.refresh();
            delta--;
        }
    }





}