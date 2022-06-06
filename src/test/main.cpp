#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


int main() {
    println("\nTest Start!\n\n");
    
    Canvas3D canvas { 120, 40 };
    
    for(int i=0; i<1000; ++i) {
        canvas.clear();

        println(canvas.getByString());
        sleep(1000/30);
    }
}