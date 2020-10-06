//
// Created by Andrea on 1/16/2020.
//

#include "Screen.h"
#include "globals.h"
#include <iostream>


Screen::Screen() {
    SetConsoleTitle("Vroom Vroom!!!");

    this->hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    //SetConsoleMode(hStdout, ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);

    //todo find a way to stop resizing. understand current solution
    //current solution modifies windows setting and doesn't allow user resizing
    //alternative solution by handling resizing events
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    //creating buffer and windows
    bufferSize = {120, 30};
    bufferPosition = {0, 0};

    //todo experiment with window size
    mainWindow = {0 , 0, 79, 24};
    statsWindow = {80, 0, 119, 24};
    windowSize = {0, 0, 119, 29};


    SetConsoleScreenBufferSize(hStdout, bufferSize);
    SetConsoleWindowInfo(hStdout, TRUE, &windowSize);
}

void Screen::clean() {
    COORD coordScreen = { 0, 0};            //cursor starting point
    DWORD dwConSize, cCharsWritten;

    GetConsoleScreenBufferInfo(hStdout, &csbInfo);
    dwConSize = csbInfo.dwSize.X * csbInfo.dwSize.Y;
    FillConsoleOutputCharacter(hStdout, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);

    GetConsoleScreenBufferInfo(hStdout, &csbInfo);
    FillConsoleOutputAttribute(hStdout, csbInfo.wAttributes, dwConSize, coordScreen, &cCharsWritten);

    SetConsoleCursorPosition(hStdout, coordScreen);
}

void Screen::drawGame() {
    DWORD charsWritten;

    WriteConsoleOutput(hStdout, consoleBuffer, bufferSize, bufferPosition, &windowSize);
    //FillConsoleOutputAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, bufferSize.X * bufferSize.Y, bufferPosition, &charsWritten);
}

void Screen::emptyBuffer() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        consoleBuffer[i].Char.AsciiChar = ' ';
        consoleBuffer[i].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
    }
}

void Screen::addToBuffer(CHAR_INFO consoleBuffer[], const COORD bufferSize,const char art[],const COORD artSize,const COORD position) {
    for (int y = 0; y < artSize.Y; y++ ) {
        for (int x = 0; x < artSize.X; x++ ) {
            if (position.X >= 0 && position.X + artSize.X <= bufferSize.X &&                 //checks if position is valid
                    position.Y >= 0 && position.Y + artSize.Y < bufferSize.Y) {
                consoleBuffer[position.X + x + (position.Y + y)* WIDTH].Char.AsciiChar = art[x + y * artSize.X];
                //todo add color variation based on entity
                consoleBuffer[position.X + x + (position.Y + y)* WIDTH].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;;
            }
        }
    }
}

/*
void Screen::addEntityToBuffer(Entity *entity, CHAR_INFO consoleBuffer[], COORD bufferSize) {
    addToBuffer(consoleBuffer, bufferSize, entity->art, entity->size, entity-> position);
}
*/

void Screen::addEntities() {
    for (manager.entityIter = manager.entityList.begin(); manager.entityIter != manager.entityList.end(); ++manager.entityIter) {
        addToBuffer(consoleBuffer, bufferSize, (*manager.entityIter)->getArt() ,(*manager.entityIter)->getSize(), (*manager.entityIter)->getPosition());
    }
}

void Screen::refresh() {
    emptyBuffer();
    //add player to buffer
    addToBuffer(consoleBuffer, bufferSize, player.art, player.size, player.position);
    addEntities();
    drawGame();
}


