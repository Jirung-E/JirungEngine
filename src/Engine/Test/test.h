#include "../Object/Object.hpp"
#include "../../Graphic/Graphic.hpp"
#include "../../Graphic/Renderer/ConsoleRenderer.hpp"
#include "../../IO/Input/Input.hpp"
#include "../../IO/ConsoleManager.hpp"

#include <cmath>

using namespace Engine;
using namespace Graphic;
using namespace Math;
using namespace IO;


void test() {
    println("\n\n\nTest Start!\n\n\n");
    
    Object ball1;
    ball1.addPolygon(new Polygon { });
    Object ball2;
    ball2.addPolygon(new Polygon { });
    ball2.rotateY(M_PI/2);
    ball2.moveTo({ 2, 0, 0 });
    ball2.physics.velocity = { 0, 1, 0 };
    
    Renderer* renderer = new ConsoleRenderer { };
    
    Input* in = new KeyboardListener { };
    
    while(true) {
        if(in->detectKeyPress()) {
            in->getInput();
            
            ball2.physics.acceleration = (ball1.getPosition() - ball2.getPosition()) / pow(Point::getDistanceBetween(ball1.getPosition(), ball2.getPosition()), 2);
            ball2.update();
            
            switch(in->getPressedKeyID()) {
                case KeyID::W:
                    renderer->camera.moveTo(renderer->camera.getPosition() + Point { renderer->camera.direction() * 0.3f });
                    break;
                case KeyID::S:
                    renderer->camera.moveTo(renderer->camera.getPosition() - Point { renderer->camera.direction() * 0.3f });
                    break;
                case KeyID::A:
                    renderer->camera.moveTo(renderer->camera.getPosition() - Point { renderer->camera.getXAxis().vector * 0.3f });
                    break;
                case KeyID::D:
                    renderer->camera.moveTo(renderer->camera.getPosition() + Point { renderer->camera.getXAxis().vector * 0.3f });
                    break;
                case KeyID::UPARROW:
                    renderer->camera.rotateX(0.02f);
                    break;
                case KeyID::DOWNARROW:
                    renderer->camera.rotateX(-0.02f);
                    break;
                case KeyID::LEFTARROW:
                    renderer->camera.rotateY(0.02f);
                    break;
                case KeyID::RIGHTARROW:
                    renderer->camera.rotateY(-0.02f);
                    break;
                case KeyID::SPACE:
                    renderer->camera.moveTo(renderer->camera.getPosition() + Point { 0, 0.2f, 0 });
                    break;
                case KeyID::C:
                    renderer->camera.moveTo(renderer->camera.getPosition() - Point { 0, 0.2f, 0 });
                    break;
            }
            
            if(in->getPressedKeyID() == KeyID::ESC) {
                break;
            }
            
            renderer->clearImage();
            for(auto e : ball1.polygons) {
                renderer->renderClear(*e);
            }
            for(auto e : ball2.polygons) {
                renderer->renderClear(*e);
            }
            
            ConsoleImage* ci = new ConsoleImage { renderer->image };
            print(ci->getByString());
        }
    }
}