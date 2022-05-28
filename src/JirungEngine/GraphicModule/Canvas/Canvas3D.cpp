#include "Canvas3D.hpp"

using namespace std;
using namespace JirungEngine;


Canvas3D::Canvas3D(size_t width, size_t height) : Canvas { width, height }, origin { static_cast<float>(width)/2, static_cast<float>(height)/2 }, 
camera_position { 0, 0, 10 }, focal_length { 10.0f } {
    
}

Canvas3D::Canvas3D() : Canvas3D { 80, 40 } {

}

Canvas3D::~Canvas3D() {
    
}


void Canvas3D::draw(const Vector& vector, const Point& point) {
    Point start_point { point };
    Point end_point { point.x + vector.x, point.y + vector.y, point.z + vector.z };
    Vector direction { vector };
    
    auto round = [](float num) -> int { return static_cast<int>(num) + 0.5 <= num ? static_cast<int>(num+1) : static_cast<int>(num); };
    
    if(vector.isParallelTo(Vector(camera_position - point)) || vector.magnitude() == 0) {
        Canvas::draw("# ", round(start_point.x + origin.x), round(start_point.y + origin.y));
        return;
    }
    
    if(start_point.z >= camera_position.z) {
        if(end_point.z >= camera_position.z) {
            return;
        }
        else {
            start_point = end_point;
            direction = vector * -1;
        }
    }
    else {
        if(end_point.z < camera_position.z) {
            Point S { camera_position.x + focal_length*(start_point.x - camera_position.x)/(camera_position.z - start_point.z),
                  camera_position.y + focal_length*(start_point.y - camera_position.y)/(camera_position.z - start_point.z), 
                  camera_position.z - focal_length };
            Point E { camera_position.x + focal_length*(end_point.x - camera_position.x)/(camera_position.z - end_point.z),
                  camera_position.y + focal_length*(end_point.y - camera_position.y)/(camera_position.z - end_point.z), 
                  camera_position.z - focal_length };
            Vector vec { E - S };
            
            int abs_x = vec.x >= 0 ? vec.x : -vec.x;
            int abs_y = vec.y >= 0 ? vec.y : -vec.y;
            int num_of_pixels = abs_x >= abs_y ? abs_x : abs_y;
            for(int i=0; i<num_of_pixels; ++i) {
                Point temp { S.x + i*(vec.x/num_of_pixels), S.y + i*(vec.y/num_of_pixels) };
                temp += origin;
                Canvas::draw("# ", round(temp.x), round(temp.y));
            }
            Canvas::draw("# ", round(E.x), round(E.y));
            
            // for(int i=0; i<=round(vec.magnitude()); ++i) {
            //     Point temp { S.x + i*(vec.x/vec.magnitude()), S.y + i*(vec.y/vec.magnitude()) };
            //     temp += origin;
            //     Canvas::draw("*", round(temp.x), round(temp.y));
            // }
            
            return;
        }
    }
}