//
// Created by Andrea on 1/22/2020.
//

#ifndef VROOMVROOM_CONTROLS_H
#define VROOMVROOM_CONTROLS_H

#ifndef WINDOWS_H
#define WINDOWS_H
#include <windows.h>
#endif

#include "../PlayerCar.h"

class Controls {
public:
    HANDLE hStdin;
    DWORD fdwMode, fdwOldMode ;

    INPUT_RECORD inBuffer[128];
    DWORD inRead, i, numberOfEvents;

    Controls();
    void handleInput(PlayerCar &playerCar);
protected:

    void handleKeyEvent(KEY_EVENT_RECORD &record, PlayerCar &playerCar);
    void handleMouseEvent(MOUSE_EVENT_RECORD record);
    void handleFocusEvent(FOCUS_EVENT_RECORD record);

};


#endif //VROOMVROOM_CONTROLS_H
