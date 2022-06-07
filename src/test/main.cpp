#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


int main() {
    println("\nTest Start!\n\n");
    
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
        
        model.rotateX(0.12);

        println(canvas.getByString());
        sleep(1000/30);
    }
    
    for(int i=0; i<200; ++i) {
        canvas.clear();
        
        canvas.Canvas::draw(to_string(i), 0, 0);
        canvas.draw(model);
        
        model.rotateY(0.12);

        println(canvas.getByString());
        sleep(1000/30);
    }
    
    for(int i=0; i<200; ++i) {
        canvas.clear();
        
        canvas.Canvas::draw(to_string(i), 0, 0);
        canvas.draw(model);
        
        model.rotateZ(0.12);

        println(canvas.getByString());
        sleep(1000/30);
    }
}