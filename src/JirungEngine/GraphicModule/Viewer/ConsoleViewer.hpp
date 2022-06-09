#ifndef __ConsoleViewer_hpp__
#define __ConsoleViewer_hpp__

#include "Viewer.hpp"


namespace JirungEngine {
    class ConsoleViewer : public Viewer {
    private:
        std::string current_color;

    public:
        ConsoleViewer();

    private:
        void changeTextColor(std::string color);
        void printPixel(const Pixel& pixel);

    public:
        void show(const Canvas* canvas);
    };
}

#endif