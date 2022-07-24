#include "../Graphic.hpp"

//#include <thread>

using namespace std;
using namespace Graphic;


void test() {
    Display display;
    display.setPixelBrightness(1, 5, 5);
    display.setPixelBrightness(2, 6, 5);
    display.setPixelBrightness(3, 7, 5);
    display.setPixelBrightness(4, 8, 5);
    display.setPixelBrightness(5, 9, 5);
    puts(display.getByString().c_str());
    
    puts("\n-------------------------------------------------------------------------\n");
    
    display.clear();
    puts(display.getByString().c_str());
}