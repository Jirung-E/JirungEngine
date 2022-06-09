#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


int main() {
    println("\nTest Start!\n\n");
    
    ConsoleViewer cv;
    Canvas3D canvas { 120, 40 };
    
    Model model;
    Point p1 { 0, 1, 0 };
    Point p2 { 0, -1, -1 };
    Point p3 { -1, -1, 1 };
    Point p4 { 1, -1, 1 };
    model.polygons[0] = Polygon { p1, p2, p3 };
    model.polygons.push_back(Polygon(p1, p2, p4));
    model.polygons.push_back(Polygon(p1, p3, p4));
    //model.polygons.push_back(Polygon(p2, p3, p4));
    model *= 10;
    
    for(int i=0; i<200; ++i) {
        canvas.clear();
        
        canvas.Canvas::draw(to_string(i), 0, 0);
        canvas.draw(model);
        canvas.draw(model.getXAxis());
        canvas.draw(model.getYAxis());
        canvas.draw(model.getZAxis());
        
        model.rotateX(0.05);

        cv.show(&canvas);
        sleep(1000/30);
    }
}