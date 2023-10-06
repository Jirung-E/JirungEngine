#include "Input.hpp"
#include "Input.hpp"

#include <stdio.h>

#ifdef __linux__
#include <unistd.h>
#include <fcntl.h>
#endif

#ifdef _WIN32
#include <conio.h>
#endif

using namespace IO;


KeyboardListener::KeyboardListener() : recent_input { KeyID::NONE } {
#ifdef __linux__
    tcflush(STDIN_FILENO, TCIFLUSH);
    tcgetattr(STDIN_FILENO, &oldt);
#endif
}

KeyboardListener::~KeyboardListener() {
    inputModeOff();
}


int IO::KeyboardListener::getChar() {
#ifdef __linux__
    return getchar();
#endif
#ifdef _WIN32
    return _getch();
#endif
}

int KeyboardListener::getKey() {
#ifdef __linux__
    int ch = getChar();
    if(ch == 27) {
        if(detectKeyPress()) {
            ch = getChar();
            if(ch == 91) {
                ch = getChar();
                ch += 27;
            }
            ch += 91;
        }
    }
    return ch;
#endif

#ifdef _WIN32
    int ch = getChar();
    if(ch == (int)KeyID::MODIFY) {
        if(detectKeyPress()) {
            ch = getChar();
            ch += (int)KeyID::MODIFY;
        }
    }
    return ch;
#endif

    return 0;
}


void KeyboardListener::inputModeOn() {
#ifdef __linux__
    struct termios newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
}

void KeyboardListener::inputModeOff() {
#ifdef __linux__
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
}


KeyID KeyboardListener::getInput() {
#ifdef __linux__
    struct termios buf = oldt;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &buf);
#endif
    int ch = getKey();
    recent_input = KeyID(ch);
#ifdef __linux__
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldt);
#endif

    return recent_input;
}

bool KeyboardListener::detectKeyPress() {
    inputModeOn();
    
#ifdef __linux__
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
#endif

#ifdef _WIN32
    return _kbhit();
#endif

}

KeyID KeyboardListener::getPressedKeyID() {
    return recent_input;
}