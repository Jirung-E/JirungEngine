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
    Point p5 { Vector { -1, 5, 10 } };
    printf("<%6.2f, %6.2f, %6.2f>\n", p5.x, p5.y, p5.z);
    Point p6;
    p6 = p4 - p5;
    printf("<%6.2f, %6.2f, %6.2f>\n", p6.x, p6.y, p6.z);
    p6 /= 5;
    printf("<%6.2f, %6.2f, %6.2f>\n", p6.x, p6.y, p6.z);
    Point p7 = p6 * 5;
    printf("<%6.2f, %6.2f, %6.2f>\n", p7.x, p7.y, p7.z);
    cout << "p6 == p7/5 ? -> " << (p7/5 == p6) << endl;
    cout << "p6 != p7/5 ? -> " << (p7/5 != p6) << endl;
    
    Point a { 0, 10, 47.8429 };
    Point b { -72, 10, -3.141592653589793 };
    Point c { 128, 10, 0 };
    Point d { 2, 10.00000001, -3.14 };
    Point e { 0, 10, 0 };
    cout << "c is in range(a, b) ? -> " << c.isInRange(a, b) << endl;
    cout << "d is in range(a, b) ? -> " << d.isInRange(a, b) << endl;
    cout << "e is in range(a, b) ? -> " << e.isInRange(a, b) << endl;
    
    cout << "distance of a, b = " << a.getDistanceTo(b) << endl;
    cout << "distance of a, b = " << Point::getDistanceBetween(a, b) << endl;
    
    Point o { Point::origin() };
    printf("<%6.2f, %6.2f, %6.2f>\n", o.x, o.y, o.z);
    cout << "distance of O, d = " << Point::getDistanceBetween(Point::origin(), d) << endl;
    printf("<%06.2f, %06.2f, %06.2f>\n", o.x, o.y, o.z);
}

void testVector() {
    Vector v1;
    printf("<%6.2f, %6.2f, %6.2f>\n", v1.x, v1.y, v1.z);
    Vector v2 { v1 + Vector(1, 1, -5) };
    v1 = { 10, 8, -72.8049 };
    printf("<%6.2f, %6.2f, %6.2f>\n", v2.x, v2.y, v2.z);
    cout << "v1 * v2 == v1.scalar(v2) ? -> " << (v1*v2 == v1.scalarProduct(v2)) << endl;
    cout << "Vector::scalar(v1, v2) == v1.scalar(v2) ? -> " << (Vector::scalarProduct(v1, v2) == v1.scalarProduct(v2)) << endl;
    Vector v3 = Vector::crossProduct(v1, v2);
    printf("<%6.2f, %6.2f, %6.2f>\n", v3.x, v3.y, v3.z);
    cout << "Vector::cross(v1, v2) == v1.cross(v2) ? -> " << (Vector::crossProduct(v1, v2) == v1.crossProduct(v2)) << endl;
    cout << "Vector::cross(v2, v1) != v1.cross(v2) ? -> " << (Vector::crossProduct(v2, v1) != v1.crossProduct(v2)) << endl;
    Vector p { Vector::crossProduct(v2, v1) };
    Vector q { v1.crossProduct(v2) };
    cout << "p // q ? -> " << Vector::isParallel(p, q) << endl;
    cout << "-p == q ? -> " << (-p == q) << endl;
    cout << "v3 * -1 == -1 * v3 ? -> " << (v3 * -1 == -1 * v3) << endl;
    
    cout << "p ㅗ v1 ? -> " << Vector::isOrthogonal(v1, p) << endl;
    cout << "angle between v1, v2 = " << v1.getAngleWith(v2) << endl;
    
    cout << "v2\'s length = " << v2.magnitude() << endl;
    cout << "v2.unit\'s length = " << v2.getUnitVector().magnitude() << endl;
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