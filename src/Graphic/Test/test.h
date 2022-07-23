#include "../Graphic.hpp"

#include <thread>

using namespace std;
using namespace Graphic;


class Point {
public:
    float x;
    float y;
    float z;
};


Point point(float x, float y, float z = 0) {
    return Point(x, y, z);
}


void testCanvas2D() {
    Canvas* canvas = new Canvas2D { 100, 100 };
    canvas->drawLine(point(4, 7), point(8, 14));
    canvas->drawCircle(point(24, 24), 7.6f);
    canvas->erase(point(7, 7));
    canvas->show();
}


void test() {
    testCanvas2D();
}