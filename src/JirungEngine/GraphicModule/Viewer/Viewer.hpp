#ifndef __Viewer_hpp__
#define __Viewer_hpp__

#include "../Display/Display.hpp"


namespace JirungEngine {
    class Viewer {
    public:
        virtual void show(const Display& display) = 0;
    };
}

#endif