#include "Input.hpp"

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

using namespace IO;


KeyboardListener::KeyboardListener() : recent_input { 0 } {
    tcflush(STDIN_FILENO, TCIFLUSH);
    tcgetattr(STDIN_FILENO, &oldt);
}

KeyboardListener::~KeyboardListener() {
    inputModeOff();
}


int KeyboardListener::getKey() {
    int ch = getchar();
    if(ch == 27) {
        if(detectKeyPress()) {
            ch = getchar();
            if(ch == 91) {
                ch = getchar();
                ch += 27;
            }
            ch += 91;
        }
    }
    return ch;
}


void KeyboardListener::inputModeOn() {
    struct termios newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void KeyboardListener::inputModeOff() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}


KeyID KeyboardListener::getInput() {
    struct termios buf = oldt;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &buf);
    int ch = getKey();
    recent_input = KeyID(ch);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldt);

    return KeyID(ch);
}

bool KeyboardListener::detectKeyPress() {
    inputModeOn();
    
    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    int ch = getchar();
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    //inputModeOff();

    if(ch != EOF) {
        //recent_input = KeyID(ch);
        ungetc(ch, stdin);
        return true;
    }
    return false;
}

KeyID KeyboardListener::getPressedKeyID() {
    return recent_input;
}