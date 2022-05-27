#include "Canvas3D.hpp"

using namespace std;
using namespace JirungEngine;


Canvas3D::Canvas3D(size_t width, size_t height) : Canvas { width, height }, camera_position { 0, 0, 10 } {

}

Canvas3D::Canvas3D() : Canvas3D { 80, 40 } {

}

Canvas3D::~Canvas3D() {
    
}


void Canvas3D::draw(const Vector& vector, const Point& point) {
    Point start_point { point };
    Point end_point { point.x + vector.x, point.y + vector.y, point.z + vector.z };
    
    if(vector.isParallelTo(Vector(camera_position - point))) {
        //just darw @
    }
    
    // Point (start_point를 z=10으로 투영시키는 점);
    // Point (end_point를 z=10으로 투영시키는 점);
    // ░▒▓█ 이것들 이용
}