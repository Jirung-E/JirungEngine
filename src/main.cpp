#include <iostream>

#include "MathModule/Math.hpp"

using namespace std;
using namespace Math;


void testPoint() {
    Point p1 { 1, 4.2, 12.8 };
    printf("<%6.2f, %6.2f, %6.2f>\n", p1.x, p1.y, p1.z);
    Point p2 = { -1, -18.64, 3860.732 };
    printf("<%6.2f, %6.2f, %6.2f>\n", p2.x, p2.y, p2.z);
    Point p3;
    printf("<%6.2f, %6.2f, %6.2f>\n", p3.x, p3.y, p3.z);
    Point p4 { p2 + p1 };
    printf("<%6.2f, %6.2f, %6.2f>\n", p4.x, p4.y, p4.z);
}

void testVector() {
    
}

void testLine() {
    
}

void testSegment() {
    
}

void testPolygon() {
    
}

void testPlane() {
    
}

void testPanel() {
    
}

void testModel() {
    
}

void testGeometry() {
    
}


int main() {
    cout << "Test" << endl;
    
    testPoint();
    testVector();
    testLine();
    testSegment();
    testPolygon();
    testPlane();
    testPanel();
    testModel();
    testGeometry();
}