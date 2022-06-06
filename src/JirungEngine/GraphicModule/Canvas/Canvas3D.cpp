#include "Canvas3D.hpp"

#include <cmath>

using namespace std;
using namespace JirungEngine;


Canvas3D::Canvas3D(size_t width, size_t height) : Canvas { width, height }, origin { static_cast<float>(width)/2, static_cast<float>(height)/2 }, 
camera_position { 0, 0, 64 }, focal_length { 64.0f } {
    
}

Canvas3D::Canvas3D() : Canvas3D { 80, 40 } {

}

Canvas3D::~Canvas3D() {
    
}


void Canvas3D::draw(char c, const Point& point) {
    Point p { point + origin };
    if(static_cast<int>(round(p.x)) < 0 || static_cast<int>(round(p.x)) >= width_max || static_cast<int>(round(p.y)) < 0 || static_cast<int>(round(p.y)) >= height_max) {
        return;
    }
    
    pixel[height_max-1 - static_cast<int>(round(p.y))][static_cast<int>(round(p.x))] = c;
}

void Canvas3D::draw(const Vector& vector, const Point& point) {
    Point start_point { point };
    Point end_point { point.x + vector.x, point.y + vector.y, point.z + vector.z };
    Vector direction { vector };
    
    if(vector.isParallelTo(Vector(camera_position - point)) || vector.magnitude() == 0) {
        draw('#', Point(start_point.x, start_point.y));
        return;
    }
    
    if(start_point.z >= camera_position.z) {
        if(end_point.z >= camera_position.z) {
            return;
        }
        else {
            Point temp { start_point };
            start_point = end_point;
            end_point = temp;
            direction = vector * -1;
        }
    }
    
    Point S { camera_position.x + focal_length*(start_point.x - camera_position.x)/(camera_position.z - start_point.z),
          camera_position.y + focal_length*(start_point.y - camera_position.y)/(camera_position.z - start_point.z), 
          camera_position.z - focal_length };
    
    Point E;
    if(end_point.z >= camera_position.z) {
        end_point.z = camera_position.z;
        Vector ctoe { end_point - camera_position };
        ctoe = ctoe.getUnitVector() * (sqrt(pow(width_max/2, 2) + pow(height_max/2, 2) + 1));
        end_point += Point { ctoe.x, ctoe.y, 0 };
        end_point.z = camera_position.z - focal_length;
    }
    E = Point { camera_position.x + focal_length*(end_point.x - camera_position.x)/(camera_position.z - end_point.z),
          camera_position.y + focal_length*(end_point.y - camera_position.y)/(camera_position.z - end_point.z), 
          camera_position.z - focal_length };
    
    Vector vec { E - S };

    int abs_x = vec.x >= 0 ? vec.x : -vec.x;
    int abs_y = vec.y >= 0 ? vec.y : -vec.y;
    int num_of_pixels = abs_x >= abs_y ? abs_x : abs_y;
    for(int i=0; i<num_of_pixels; ++i) {
        Point temp { S.x + i*(vec.x/num_of_pixels), S.y + i*(vec.y/num_of_pixels) };
        temp -= camera_position;
        draw('#', Point(temp.x, temp.y));
    }
}

void Canvas3D::draw(const Panel& panel) {
    if(panel.normal_vector.magnitude() == 0.0f) {
        return;
    }
    
    Point LT { panel.leftTop() };
    Point RT { panel.rightTop() };
    Point LB { panel.leftBottom() };
    Point RB { panel.rightBottom() };

    draw(Vector(RT - LT), LT);
    draw(Vector(RB - LB), LB);
    draw(Vector(LB - LT), LT);
    draw(Vector(RB - RT), RT);
    draw(Vector(RB - LT), LT);
    draw(Vector(LB - RT), RT);
}


void Canvas3D::moveCameraTo(const Point& point) {
    camera_position = point;
    clear();
}


Point Canvas3D::getCameraPosition() const {
    return camera_position;
}