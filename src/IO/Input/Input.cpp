#include "Input.hpp"

#include <stdio.h>
#include <termios.h>
#include <unistd.h>


using namespace IO;


int KeyboardListener::getPressedKeyId() {
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    struct termios newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return ch;
}


bool KeyboardListener::getKeyDown(int id) {
    
}

bool KeyboardListener::getKeyPressed(int id) {
    
}

bool KeyboardListener::getKeyUp(int id) {
    
}
