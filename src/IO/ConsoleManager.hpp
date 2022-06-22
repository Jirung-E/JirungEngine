#ifndef __ConsoleManager_hpp__
#define __ConsoleManager_hpp__

#include <iostream>


namespace IO {
    void setxy(int x, int y);
    
    void print(std::string str = " ");
    void println(std::string str = "");
}

#endif