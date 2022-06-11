#ifndef __ConsoleViewer_hpp__
#define __ConsoleViewer_hpp__

#include "Viewer.hpp"


namespace JirungEngine {
    class ConsoleViewer : public Viewer {
    public:
        void show(const Display& display);
    };
}

#endif