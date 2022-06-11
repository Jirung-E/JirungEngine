#ifndef __Viewer_hpp__
#define __Viewer_hpp__

#include "../Canvas/Canvas.hpp"


namespace JirungEngine {
    class Viewer {
    public:
        virtual void show(const Canvas& canvas) = 0;
    };
}

#endif