#include <iostream>

#include "../Math.hpp"

using namespace std;
using namespace Math;


void print(const Point& point, string end = "\n") {
    printf("< %6.2f, %6.2f, %6.2f >%s", point.x, point.y, point.z, end.c_str());
}


void testPoint() {
    Point p1;
    print(p1);
    Point p2 { 1, 2, 3 };
    print(p2);
    Point p3 { -1, 4 };
    print(p3);
    Point p4 { p3 };
    print(p4);
}


int main() {
    testPoint();
}