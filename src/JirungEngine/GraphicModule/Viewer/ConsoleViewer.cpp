#include "ConsoleViewer.hpp"

#include "../../../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


ConsoleViewer::ConsoleViewer() : current_color { "WHITE" } {

}

void ConsoleViewer::changeTextColor(std::string color) {
    // if(color == current_color) {
    //     return;
    // }
    print("\x1b[31m");
}

void ConsoleViewer::printPixel(const Pixel& pixel) {
    changeTextColor(pixel.color);
    
    string str = "\x1b[31m";
    str += pixel.shape;
    print(str);
}

void ConsoleViewer::show(const Canvas* canvas) {
    string img = "";
    
    Pixel** image = canvas->get();
    for(int i=0; i<canvas->height; ++i) {
        for(int k=0; k<canvas->width; ++k) {
            img += "\x1b[31m";
            img += image[i][k].shape;
            //printPixel(image[i][k]);
        }
        img += "\n";
    }
    
    println(img);
}