#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


class TestGame : public Game {
private:
    Object o[10];
    Object ground { "ground" };
    
public:
    TestGame() : Game { Canvas(120, 45) } {
        play();
    }
    
public:
    void play() {
        for(Object& e : o) {
            e.image = new TextImage { "resource/o.txtimg" };
            e.position = Point { getRandomFloat(20, canvas.width - 20), getRandomFloat(10, canvas.height - 10) };
            e.physics.velocity = Vector { getRandomFloat(-0.2, 0.2), getRandomFloat(-0.2, 0.2) };
            e.physics.gravity = Vector { 0, 9.8f / 1000 };
        }
        
        ground.image = new TextImage { "resource/ground.txtimg" };
        ground.addCollider(ground.position, Vector(canvas.width, 0, 0));
        for(int i=0; i<canvas.width; i+=canvas.width) {
            ground.position = Point { static_cast<float>(i), 40 };
        }
        
        for(Object* o : Object::object_list) {
            o->update();
        }
        
        while(true) {
            update();
            
            sleep(1000/60);
        }
    }
    
private:
    void update() {
        canvas.clear();
        for(Object* o : Object::object_list) {
            canvas.draw(*o);
        }
        println(canvas.getByString());

        for(Object* o : Object::object_list) {
            o->update();
        }
        
        EventListener::collisionCheck();
        
        for(Object* o : Object::object_list) {
            if(o->isCollide()) {
                o->image = new TextImage { "resource/x.txtimg" };
            }
        }
    }
};

void nemo() {
    Canvas3D canvas { 120, 90 };
    
    for(int i=0; i<10000; ++i) {
        canvas.draw(Vector(0, 0, 20), Point(-10, 5, -15) + Point(-22, 0, 0));
        canvas.draw(Vector(0, 0, 20), Point(10, 5, -15) + Point(-22, 0, 0));
        canvas.draw(Vector(0, 0, 20), Point(-10, -10, -15) + Point(-22, 0, 0));
        canvas.draw(Vector(0, 0, 20), Point(10, -10, -15) + Point(-22, 0, 0));

        canvas.draw(Vector(20, 0, 0), Point(-10, 5, -15) + Point(-22, 0, 0));
        canvas.draw(Vector(20, 0, 0), Point(-10, 5, 5) + Point(-22, 0, 0));
        canvas.draw(Vector(20, 0, 0), Point(-10, -10, -15) + Point(-22, 0, 0));
        canvas.draw(Vector(20, 0, 0), Point(-10, -10, 5) + Point(-22, 0, 0));

        canvas.draw(Vector(0, 15, 0), Point(-10, -10, -15) + Point(-22, 0, 0));
        canvas.draw(Vector(0, 15, 0), Point(-10, -10, 5) + Point(-22, 0, 0));
        canvas.draw(Vector(0, 15, 0), Point(10, -10, -15) + Point(-22, 0, 0));
        canvas.draw(Vector(0, 15, 0), Point(10, -10, 5) + Point(-22, 0, 0));
        
        
        canvas.draw(Vector(0, 0, 20), Point(-10, 5, -15) + Point(5, 0, 0));
        canvas.draw(Vector(0, 0, 20), Point(10, 5, -15) + Point(5, 0, 0));
        canvas.draw(Vector(0, 0, 20), Point(-10, -10, -15) + Point(5, 0, 0));
        canvas.draw(Vector(0, 0, 20), Point(10, -10, -15) + Point(5, 0, 0));

        canvas.draw(Vector(20, 0, 0), Point(-10, 5, -15) + Point(5, 0, 0));
        canvas.draw(Vector(20, 0, 0), Point(-10, 5, 5) + Point(5, 0, 0));
        canvas.draw(Vector(20, 0, 0), Point(-10, -10, -15) + Point(5, 0, 0));
        canvas.draw(Vector(20, 0, 0), Point(-10, -10, 5) + Point(5, 0, 0));

        canvas.draw(Vector(0, 15, 0), Point(-10, -10, -15) + Point(5, 0, 0));
        canvas.draw(Vector(0, 15, 0), Point(-10, -10, 5) + Point(5, 0, 0));
        canvas.draw(Vector(0, 15, 0), Point(10, -10, -15) + Point(5, 0, 0));
        canvas.draw(Vector(0, 15, 0), Point(10, -10, 5) + Point(5, 0, 0));
        
        
        canvas.draw(Vector(0, 150, 0), Point(0, 0, 0));

        println("\n\n\n\n\n\n\n\n\n");
        println(canvas.getByString());
        
        canvas.moveCameraTo(canvas.getCameraPosition() + Point(0, 0, -0.2));
        
        sleep(1000/30);
    }
}

int main() {
    println("\nTest Start!\n\n");
    
    //TestGame();
    Canvas3D canvas { 120, 40 };
    
    Panel panel;
    // panel.point = { -5, 10, 2 };
    panel.normal_vector = { 10, 10, 10 };
    canvas.draw(panel);
    canvas.draw('@', Point(0, 0));
    
    println(canvas.getByString());
    
    //println("░▒▓█");
}