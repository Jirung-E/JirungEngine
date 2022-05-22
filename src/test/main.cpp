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
    obj1.position = Point { 30, 30 };
    obj1.physics.velocity = Vector { 0, 0.1 };
    
    Object obj2;
    obj2.image = new TextImage { "resource/x.txtimg" };
    obj2.position = Point { 70, 30 };
    obj2.physics.velocity = Vector { 0, -0.1 };
    
    while(true) {
        canvas.clear();
        canvas.draw(obj1);
        canvas.draw(obj2);
        println(canvas.getByString());
        
        Vector obj1_to_obj2 { obj2.position - obj1.position };
        float r = obj1_to_obj2.magnitude();
        obj1.physics.gravity = obj1_to_obj2 / (r * r);
        obj2.physics.gravity = (obj1_to_obj2 / (r * r)) * -1;
        
        obj1.update();
        obj2.update();
        
        sleep(1000/60);
    }
}

int main() {
    println("\nTest Start!\n\n");
    
    test();
}