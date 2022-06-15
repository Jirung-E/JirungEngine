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
    
    for(int i=0; i<1000; ++i) {
        renderer.renderClear(p);
        viewer->show(*renderer.image);
        
        p.moveTo(p.p1 + Point(0, 0, -1));
        p.rotate(Line(p.getCenterOfGravity(), p.getNormal()), 0.1);
        
        sleep(1000/30);
    }
}