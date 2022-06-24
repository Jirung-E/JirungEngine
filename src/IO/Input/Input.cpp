#include "Input.hpp"

#include <stdio.h>
#include <termios.h>
#include <unistd.h>


using namespace IO;


KeyID KeyboardListener::getPressedKeyId() {
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    struct termios newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return KeyID(ch);
}


bool KeyboardListener::getKeyDown(KeyID id) {
    return false;
}

bool KeyboardListener::getKeyPressed(KeyID id) {
    return false;
}

bool KeyboardListener::getKeyUp(KeyID id) {
    return false;
}
