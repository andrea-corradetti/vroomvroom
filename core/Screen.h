//
// Created by Andrea on 1/16/2020.
//

#ifndef VROOMVROOM_SCREEN_H
#define VROOMVROOM_SCREEN_H

#ifndef WINDOWS_H
#define WINDOWS_H
#include <windows.h>
#endif

#include "Entity.h"
#include "globals.h"

#define WIDTH 120
#define HEIGHT 30


class Screen {
public:
    HANDLE hStdin, hStdout;
    CONSOLE_SCREEN_BUFFER_INFO csbInfo;
    WORD wOldColorAttrs;
    DWORD fdwMode, fdwOldMode ;

    COORD bufferSize, oldBufferSize;                //size of the whole console buffer
    COORD bufferPosition;
    SMALL_RECT mainWindow;       //console portion where game is rendered
    SMALL_RECT statsWindow;      //...where stats and score are rendered
    SMALL_RECT windowSize;           //whole window

    CHAR_INFO consoleBuffer[60 * 120];  //handled as a matrix

    Screen();
    void clean();
    void drawStats();
    void refresh();
    void addToBuffer(CHAR_INFO consoleBuffer[], COORD bufferSize,const char art[],const COORD artSize,const COORD position);
    void addEntityToBuffer(Entity *entity, CHAR_INFO consoleBuffer[], COORD bufferSize);

private:
    void drawGame();
    void emptyBuffer();
    void addPlayer();
    void addEntities();
};


#endif //VROOMVROOM_SCREEN_H
