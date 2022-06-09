#ifndef __ConsoleViewer_hpp__
#define __ConsoleViewer_hpp__

#include "Viewer.hpp"


namespace JirungEngine {
    class ConsoleViewer : public Viewer {
    private:
        static std::string current_color;

    private:
        static void changeTextColor(std::string color);
        static void printPixel(const Pixel& pixel);

    public:
        static void show(const Canvas* canvas);
    };
}

#endif