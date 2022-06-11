#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


int main() {
    println("\nTest Start!\n\n");

    Viewer* viewer = new ConsoleViewer();
    Renderer renderer;
    Polygon p;
    Canvas canvas;
    canvas.default_background = '#';
    canvas.clear();
    viewer->show(canvas);
    canvas = renderer.renderGeneral(p);
    viewer->show(canvas);
    viewer->show(renderer.image);
}