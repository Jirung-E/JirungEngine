#ifndef __ConsoleViewer_hpp__
#define __ConsoleViewer_hpp__

#include "Viewer.hpp"


namespace JirungEngine {
    class ConsoleViewer : public Viewer {
    private:
        static void changeTextColor(std::string color);

    public:
        static void show(const Canvas* canvas);
    };
}

#endif