#include "ConsoleManager.hpp"

using namespace std;
using namespace IO;


void IO::setxy(int x, int y) {
    putchar('\0');
    printf("\x1b[%d;%dH", y, x);
}

void IO::clear() {
#ifdef __linux__
    system("clear");
#endif
#ifdef _WIN32
    system("cls");
#endif
}


void IO::print(string str) {
    printf("%s", str.c_str());
}

void IO::println(string str) {
    printf("%s\n", str.c_str());
}
