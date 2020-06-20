//
// Created by Lukas on 2020-06-11.
//

#ifndef LJENGINE_KEYHANDLER_H
#define LJENGINE_KEYHANDLER_H


class KeyHandler {
private:
    static int key;
    KeyHandler();
public:
    static void setKeyPressed(int keyCode);
    static void ReleaseKey();
    static int getKeyPressed();
};


#endif //LJENGINE_KEYHANDLER_H
