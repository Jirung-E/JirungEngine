#include "Input.hpp"

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

using namespace IO;


struct termios KeyboardListener::oldt;


void KeyboardListener::inputModeOn() {
    tcgetattr(STDIN_FILENO, &oldt);
    struct termios newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void KeyboardListener::inputModeOff() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}


KeyID KeyboardListener::getPressedKeyId() {
    struct termios buf = oldt;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &buf);
    int ch = getchar();
    recent_input = KeyID(ch);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldt);

    return KeyID(ch);
}

bool KeyboardListener::detectKeyPress() {
    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    int ch = getchar();
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }
    return false;
}


bool KeyboardListener::getKeyDown(KeyID id) {
    if(recent_input == id) {
        return true;
    }
    return false;
}

bool KeyboardListener::getKeyDownNow(KeyID id) {
    return false;
}

bool KeyboardListener::getKeyUpNow(KeyID id) {
    return false;
}

KeyState KeyboardListener::getCurrentKeyState(KeyID id) {
    return Key::getState(id);
}


KeyState Key::getState(KeyID id) {
    return KeyState::UP;
}