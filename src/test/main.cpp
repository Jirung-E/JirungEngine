#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


int main() {
    println("\nTest Start!\n\n");

    Point p1 { 1, 5, 2 };
    Point p2 { -1, 9, -7 };
    Vector v { 1, 1, 1 };
    
    printf("%.2f %.2f %.2f\n", p2.x, p2.y, p2.z);
    Point p3 = p1 + v;
    printf("%f %f %f\n", p3.x, p3.y, p3.z);
    p3 += v;
    printf("%f %f %f\n", p3.x, p3.y, p3.z);
    
    Point po { v };
    printf("%f %f %f\n", po.x, po.y, po.z);
}