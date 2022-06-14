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
    renderer.renderGeneral(p);
    viewer->show(renderer.image);
}