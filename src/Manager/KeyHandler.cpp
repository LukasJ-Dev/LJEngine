//
// Created by Lukas on 2020-06-11.
//

#include <iostream>
#include "KeyHandler.h"

int KeyHandler::key;

void KeyHandler::setKeyPressed(int keyCode) {
    key = keyCode;
}

void KeyHandler::ReleaseKey() {
    key = 0;
}

int KeyHandler::getKeyPressed() {
    return key;
}