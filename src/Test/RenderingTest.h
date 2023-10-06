#include "../Math/Math.hpp"
#include "../IO/Input.hpp"
#include "../IO/ConsoleManager.hpp"
#include "../Graphic/Graphic.hpp"
#include "../Graphic/ConsoleImage.hpp"
#include "../Graphic/ConsoleRenderer.hpp"

#include <thread>
#include <chrono>

using namespace std;
using namespace Math;
using namespace IO;
using namespace Graphic;


namespace RenderingTest {
    void sleep(unsigned short time) {
        this_thread::sleep_for(chrono::milliseconds(time));
    }


    void showLoadingAnimation() {
        setxy(10, 10);
        print("#");
        sleep(100);
        setxy(10, 10);
        print(" ");

        setxy(11, 10);
        print("#");
        sleep(100);
        setxy(11, 10);
        print(" ");

        setxy(12, 10);
        print("#");
        sleep(100);
        setxy(12, 10);
        print(" ");

        setxy(12, 11);
        print("#");
        sleep(100);
        setxy(12, 11);
        print(" ");

        setxy(12, 12);
        print("#");
        sleep(100);
        setxy(12, 12);
        print(" ");

        setxy(11, 12);
        print("#");
        sleep(100);
        setxy(11, 12);
        print(" ");

        setxy(10, 12);
        print("#");
        sleep(100);
        setxy(10, 12);
        print(" ");

        setxy(10, 11);
        print("#");
        sleep(100);
        setxy(10, 11);
        print(" ");
    }

    void testIOandMath() {
        clear();

        Point p[2];
        int n = 0;

        setxy(1, 1);
        println("Press Enter to show p[0] + p[1], Press Space to change values, Press ESC to exit program.");
        printf("p[%d] =        ( %f, %f, %f )   \n", 0, p[0].x, p[0].y, p[0].z);
        printf("p[%d] =        ( %f, %f, %f )   \n", 1, p[1].x, p[1].y, p[1].z);

        thread graphic_thread { [&]() { while(true)showLoadingAnimation(); } };

        Input* in = new KeyboardListener { };
        while(true) {
            if(in->detectKeyPress()) {
                in->getInput();
                if(in->getPressedKeyID() == KeyID::SPACE) {
                    if(n >= 2) {
                        n = 0;
                    }
                    p[n].x = getRandomFloat(-10.0f, 10.0f);
                    p[n].y = getRandomFloat(-10.0f, 10.0f);
                    p[n].z = getRandomFloat(-10.0f, 10.0f);
                    setxy(1, n+2);
                    printf("p[%d] =        ( %f, %f, %f )   ", n, p[n].x, p[n].y, p[n].z);
                    n++;
                }
                if(in->getPressedKeyID() == KeyID::ENTER) {
                    setxy(1, 5);
                    printf("p[0] + p[1] = ( %f, %f, %f )   \n", p[0].x + p[1].x, p[0].y + p[1].y, p[0].z + p[1].z);
                }
                if(in->getPressedKeyID() == KeyID::ESC) {
                    break;
                }
            }
        }

        graphic_thread.detach();
    }


    void testRenderer() {
        println("\nTest Start!\n\n");

        Point p[] = {
            { -1, -1, -1 },
            { 1, -1, -1 },
            { -1, -1, 1 },
            { 1, -1, 1 },
            { -1, 1, -1 },
            { 1, 1, -1 },
            { -1, 1, 1 },
            { 1, 1, 1 }
        };
        
        Model cube;
        cube.polygons.reserve(12);
        cube.polygons.push_back(Polygon { p[0], p[1], p[2] });
        cube.polygons.push_back(Polygon { p[1], p[3], p[2] });
        cube.polygons.push_back(Polygon { p[0], p[4], p[1] });
        cube.polygons.push_back(Polygon { p[1], p[4], p[5] });
        cube.polygons.push_back(Polygon { p[0], p[2], p[4] });
        cube.polygons.push_back(Polygon { p[2], p[6], p[4] });
        cube.polygons.push_back(Polygon { p[1], p[5], p[3] });
        cube.polygons.push_back(Polygon { p[3], p[5], p[7] });
        cube.polygons.push_back(Polygon { p[2], p[3], p[6] });
        cube.polygons.push_back(Polygon { p[3], p[7], p[6] });
        cube.polygons.push_back(Polygon { p[4], p[6], p[5] });
        cube.polygons.push_back(Polygon { p[5], p[6], p[7] });

        Renderer* renderer = new ConsoleRenderer { 156, 44 };
        renderer->camera.moveTo({ 0, 0, 2 });

        Input* in = new KeyboardListener { };
        in->getInput();

        while(true) {
            setxy(0, 0);
            if(in->detectKeyPress()) {
                
                in->getInput();

                switch(in->getPressedKeyID()) {
                case KeyID::W:
                    renderer->camera.moveTo(renderer->camera.getPosition() + Vector { renderer->camera.direction().x, 0, renderer->camera.direction().z });
                    break;
                case KeyID::S:
                    renderer->camera.moveTo(renderer->camera.getPosition() - Vector { renderer->camera.direction().x, 0, renderer->camera.direction().z });
                    break;
                case KeyID::A:
                    renderer->camera.moveTo(renderer->camera.getPosition() - Vector { renderer->camera.getXAxis().vector * 0.3f });
                    break;
                case KeyID::D:
                    renderer->camera.moveTo(renderer->camera.getPosition() + Vector { renderer->camera.getXAxis().vector * 0.3f });
                    break;
                case KeyID::UPARROW:
                    renderer->camera.rotate(renderer->camera.getXAxis().vector, -0.02f);
                    break;
                case KeyID::DOWNARROW:
                    renderer->camera.rotate(renderer->camera.getXAxis().vector, 0.02f);
                    break;
                case KeyID::LEFTARROW:
                    //renderer->camera.rotateY(0.02f);
                    renderer->camera.rotate(Vector::j(), -0.02f);
                    break;
                case KeyID::RIGHTARROW:
                    //renderer->camera.rotateY(-0.02f);
                    renderer->camera.rotate(Vector::j(), 0.02f);
                    break;
                case KeyID::SPACE:
                    renderer->camera.moveTo(renderer->camera.getPosition() + Vector { 0, 0.2f, 0 });
                    break;
                case KeyID::C:
                    renderer->camera.moveTo(renderer->camera.getPosition() - Vector { 0, 0.2f, 0 });
                    break;
                case KeyID::Z:
                    renderer->camera.field_of_view += 0.1f;
                    break;
                case KeyID::X:
                    renderer->camera.field_of_view -= 0.1f;
                    break;
                }

                if(in->getPressedKeyID() == KeyID::ESC) {
                    break;
                }
            }

            cube.rotateX(0.01f);
            cube.rotateY(0.01f);
            cube.rotateZ(0.01f);

            renderer->clearImage();
            renderer->renderGeneral(cube);

            Renderer::Camera& cam = renderer->camera;
            Image* img = renderer->image;

            Point position = cam.getPosition();
            printf("x: %7.2f      y: %7.2f      z: %7.2f", position.x, position.y, position.z);
            string space(img->getWidth()-42, ' ');
            println(space);

            Vector facing = cam.direction();
            printf("facing: %5.2f, %5.2f, %5.2f", facing.x, facing.y, facing.z);
            space.resize(img->getWidth()-27, ' ');
            println(space);

            printf("fov: %7.2f", cam.field_of_view);
            space.resize(img->getWidth()-12, ' ');
            println(space);

            ConsoleImage* ci = new ConsoleImage { img };
            print(ci->getByString());
        }
    }


    void testGraphicThread() {
        Renderer* renderer = new ConsoleRenderer { };

        const int num_of_polygons = 50;
        Polygon pol[num_of_polygons];
        for(int i=0; i<num_of_polygons; ++i) {
            pol[i].moveTo({ pol[i].p1 - Point { 0, 0, -50.0f + i*3.0f } });
            pol[i].rotate(Line(pol[i].centerOfGravity(), pol[i].normal()), i/10.0f);
        }

        thread graphic_thread { [&]() {
            while(true) {
                renderer->clearImage();
                for(const Polygon& e : pol) {
                    renderer->renderClear(e);
                }

                ConsoleImage* ci = new ConsoleImage { renderer->image };
                print(ci->getByString());
                sleep(1000/30);
            }
        } };

        sleep(10000);

        graphic_thread.detach();
    }


    void test() {
        testRenderer();
    }
}