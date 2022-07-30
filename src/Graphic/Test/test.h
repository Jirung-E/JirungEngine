#include "../Graphic.hpp"

//#include <thread>

using namespace std;
using namespace Graphic;


void test1() {
    Display display;
    Image image;
    image.setPixelBrightness(1, 5, 5);
    image.setPixelBrightness(2, 6, 5);
    image.setPixelBrightness(3, 7, 5);
    image.setPixelBrightness(4, 8, 5);
    image.setPixelBrightness(5, 9, 5);
    image.setPixelBrightness(6, 10, 5);
    image.setPixelBrightness(7, 11, 5);
    image.setPixelBrightness(8, 12, 5);
    display.showImage(&image);
    puts(display.getByString().c_str());
    
    puts("\n-------------------------------------------------------------------------\n");
    
    display.clear();
    puts(display.getByString().c_str());
}

void test2() {
    Display* display = new ConsoleDisplay { };
    Image* img = new ConsoleImage { };
    
}


void test() {

}