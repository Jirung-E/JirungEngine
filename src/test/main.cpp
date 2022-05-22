#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


void test() {
    Canvas canvas(100, 40);
    //canvas.setDefaultBackground('.');
    println(canvas.getByString());
    
    Object obj1;
    obj1.image = new TextImage { "resource/o.txtimg" };
    obj1.position = Point { 30, 20 };
    //obj1.physics.velocity = Vector { 0, 0.1 };
    obj1.addCollider(obj1.position, Vector(1, 0));
    
    Object obj2;
    obj2.image = new TextImage { "resource/x.txtimg" };
    obj2.position = Point { 70, 20 };
    //obj2.physics.velocity = Vector { 0, -0.1 };
    obj2.addCollider(obj2.position, Vector(-1, 0));
    
    while(true) {
        canvas.clear();
        canvas.draw(obj1);
        canvas.draw(obj2);
        canvas.draw(to_string(obj1.physics.velocity.x), 1, 3);
        println(canvas.getByString());
        
        if(obj1.isCollidingWith(obj2)) {
            break;
        }
        
        Vector obj1_to_obj2 { obj2.position - obj1.position };
        float r = obj1_to_obj2.magnitude();
        obj1.physics.gravity = obj1_to_obj2 / (r * r);
        obj2.physics.gravity = (obj1_to_obj2 / (r * r)) * -1;
        
        obj1.update();
        obj2.update();
        
        sleep(1000/60);
    }
}

void segmentTest() {
    Segment s1 { Point(1, 1, 1), Vector(1, -1, 1) };
    Segment s2 { Point(0, 0, 0), Vector(1, -1, 1) };
    Segment s3 { Point(1, 0, 0), Vector(1, 2, 1) };
    
    Canvas canvas;
    Point origin { 40, 20 };
    canvas.draw(s1, origin);
    canvas.draw(s2, origin);
    canvas.draw(s3, origin);
    
    println(canvas.getByString());
    
    println("s1, s2 distance: " + to_string(Segment::getDistanceBetween(s1, s2)));
    println("s1, s3 distance: " + to_string(s1.getDistanceTo(s3)));
    println("s1, s2.point distance: " + to_string(s1.getDistanceTo(s2.point)));
}

int main() {
    println("\nTest Start!\n\n");
    
    //segmentTest();
    test();
}