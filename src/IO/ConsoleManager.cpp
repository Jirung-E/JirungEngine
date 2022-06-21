#include "ConsoleManager.hpp"

using namespace IO;


void ConsoleManager::setxy(int x, int y) {
    printf("\x1b[%d;%dH", y, x);
}
