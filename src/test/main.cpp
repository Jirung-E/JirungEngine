#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


class TestGame : public Game {
private:
    Object obj1;
    Object obj2;
    Object obj3;
    Object ground;
    
public:
    TestGame() : Game { Canvas(120, 45) } {
        play();
    }
    
public:
    void play() {
        obj1.image = new TextImage { "resource/o.txtimg" };
        obj1.position = Point { 30, 20 };

        obj2.image = new TextImage { "resource/x.txtimg" };
        obj2.position = Point { 70, 20 };

        obj3.image = new TextImage { "resource/o.txtimg" };
        obj3.position = Point { 50, 10, 1 };
        obj3.physics.gravity.y = 9.8f / 1000;
        obj3.addCollider(Point(0, 0, 0), Vector(0, 10, 0));

        ground.image = new TextImage { "resource/ground.txtimg" };
        ground.position = Point { 48, 25, 1 };
        ground.addCollider(Point(0, 0, 0), Vector(ground.image->getWidth()-1, 0, 0));

        obj1.update();
        obj2.update();
        obj3.update();
        ground.update();
        
        while(true) {
            update();
            
            sleep(1000/60);
        }
    }
    
private:
    void update() {
        canvas.clear();
        canvas.draw(obj1);
        canvas.draw(obj2);
        canvas.draw(obj2);
        canvas.draw(ground);
        canvas.draw(obj3);
        canvas.draw(to_string(obj1.position.x), 1, 2);
        canvas.draw(to_string(obj1.physics.velocity.x), 1, 3);
        canvas.draw(to_string(obj3.getNumOfColliders()), 1, 4);
        canvas.draw(to_string(ground.getNumOfColliders()), 5, 4);
        canvas.draw(to_string(obj1.collider.front().start_point.z), 90, 1);
        canvas.draw(to_string(obj2.collider.front().start_point.z), 90, 2);
        canvas.draw(to_string(obj3.collider.front().start_point.z), 90, 3);
        canvas.draw(to_string(ground.collider.front().start_point.z), 90, 4);
        
        println(canvas.getByString());
        
        Vector obj1_to_obj2 { obj2.position - obj1.position };
        float r = obj1_to_obj2.magnitude();
        obj1.physics.gravity = obj1_to_obj2 / (r * r);
        obj2.physics.gravity = (obj1_to_obj2 / (r * r)) * -1;
        

        for(Object* o : Object::object_list) {
            o->update();
        }
        
        EventListener::collisionCheck();
        
        if(obj1.isCollide()) {
            println("1!");
            obj1.backToPrevFrame();
            obj1.physics.velocity *= -1;
        }
        if(obj2.isCollide()) {
            println("2!");
            obj2.backToPrevFrame();
            obj2.physics.velocity *= -1;
        }
        if(obj3.isCollide()) {
            println("3!");
            obj3.backToPrevFrame();
            obj3.physics.velocity *= -1;
        }
    }
};

int main() {
    println("\nTest Start!\n\n");
    
    TestGame();
}