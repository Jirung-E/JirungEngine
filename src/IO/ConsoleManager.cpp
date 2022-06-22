#include "ConsoleManager.hpp"

#include <iostream>

using namespace IO;


void IO::setxy(int x, int y) {
    printf("\x1b[%d;%dH", y, x);
}