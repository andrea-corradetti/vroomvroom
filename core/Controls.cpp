//
// Created by Andrea on 1/22/2020.
//

#include "Controls.h"
#include <iostream>
//todo handle resize events

Controls::Controls() {
    this->hStdin = GetStdHandle(STD_INPUT_HANDLE);

    GetConsoleMode(hStdin, &fdwOldMode);
    fdwMode = fdwOldMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT ) | ENABLE_EXTENDED_FLAGS;
    SetConsoleMode(hStdin, fdwMode);
    FlushConsoleInputBuffer(hStdin);
}


void Controls::handleInput(PlayerCar &playerCar) {
    GetNumberOfConsoleInputEvents(hStdin, &numberOfEvents);
    if (numberOfEvents > 0) {                                                                       //checks for input to avoid stopping
        ReadConsoleInput(hStdin, inBuffer, 128, &inRead);
        for (i = 0; i<inRead; i++)
        {
            switch (inBuffer[i].EventType)
            {
                case KEY_EVENT:

                    handleKeyEvent(inBuffer[i].Event.KeyEvent, playerCar);
                    break;
/*

            case MOUSE_EVENT:
                handleMouseEvent(inBuffer[i].Event.MouseEvent);
                break;
*/

                case FOCUS_EVENT:
                    handleFocusEvent(inBuffer[i].Event.FocusEvent);
                    break;

                default:
                    break;
            }
        }
    }

}

void Controls::handleKeyEvent(KEY_EVENT_RECORD &record, PlayerCar &player) {
        switch (record.wVirtualKeyCode) {
            case VK_LEFT:
                player.moveLeft();
                break;
            case VK_RIGHT:
                player.moveRight();
                break;
            case VK_UP:
                player.moveUp();
                break;
            case VK_DOWN:
                player.moveDown();
                break;
            case VK_ESCAPE:
                //todo add menu function
                std::cout << "escape" << std::endl;
                break;

        }
}
void Controls::handleMouseEvent(MOUSE_EVENT_RECORD record) {

}

void Controls::handleFocusEvent(FOCUS_EVENT_RECORD record) {

}