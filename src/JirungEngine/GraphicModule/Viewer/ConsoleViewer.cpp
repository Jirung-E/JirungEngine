#include "ConsoleViewer.hpp"

#include "../../../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


ConsoleViewer::ConsoleViewer() : current_color { "WHITE" } {

}

void ConsoleViewer::changeTextColor(std::string color) {
    if(color == current_color) {
        return;
    }
    system("echo -e \"\x1b[31m\"");
}

void ConsoleViewer::printPixel(const Pixel& pixel) {
    changeTextColor(pixel.color);
    print(to_string(pixel.shape));
}

void ConsoleViewer::show(const Canvas* canvas) {
    Pixel** image = canvas->get();
    for(int i=0; i<canvas->height; ++i) {
        for(int k=0; k<canvas->width; ++k) {
            printPixel(image[i][k]);
        }
    }
}