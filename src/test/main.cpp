#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


int main() {
    println("\nTest Start!\n\n");
    
    Canvas3D canvas { 120, 40 };
    
    Polygon polygon;
    polygon.moveTo(polygon.p1 + Point(-20, 0, 0));
    polygon *= 10;
    
    Line axis { Point { 0, 0, 0 }, Vector::j() };
    
    for(int i=0; i<1000; ++i) {
        canvas.clear();
        
        canvas.Canvas::draw(to_string(i), 0, 0);
        canvas.draw(polygon);
        
        polygon.rotate(Line(polygon.getCenterOfGravity(), polygon.getNormal()), 0.1);
        polygon.rotate(Line(polygon.getCenterOfGravity(), Vector::j()), 0.1);
        polygon.rotate(axis, 0.05);

        println(canvas.getByString());
        sleep(1000/30);
    }
}