#include "ConsoleViewer.hpp"

#include "../../../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


void ConsoleViewer::changeTextColor(std::string color) {
    system("echo -e \"\x1b[31m RED TEST\"")
}

void ConsoleViewer::show(const Canvas* canvas) {
    Pixel** image = canvas->get();
    for(int i=0; i<canvas->height; ++i) {
        for(int k=0; k<canvas->width; ++k) {
            changeTextColor(image[i][k].color)
        }
    }
}