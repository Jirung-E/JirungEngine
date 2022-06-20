#ifndef __Util_hpp__
#define __Util_hpp__

#include <iostream>

#include "UtilType.hpp"


namespace Util {
    void print(str_t text = " ");
    void println(str_t text = "");

    void sleep(unsigned short time);
    
    int getRandomInt(int from, int to);
    float getRandomFloat(float from, float to);
}

#endif