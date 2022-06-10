#include "ConsoleViewer.hpp"

#include "../../../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


ConsoleViewer::ConsoleViewer() : current_color { "WHITE" } {

}

void ConsoleViewer::changeTextColor(std::string color) {
    
}

void ConsoleViewer::printPixel(const Pixel& pixel) {
    
}

void ConsoleViewer::show(const Canvas* canvas) {
    println(canvas->getByString());
}