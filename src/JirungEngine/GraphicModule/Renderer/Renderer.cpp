#include "Renderer.hpp"

using namespace std;
using namespace JirungEngine;


Renderer::Camera::Camera() : position { 0, 0, 64 }, direction { 0, 0, -1 } {

}

Renderer::Renderer(unsigned short int width, unsigned short int height) : camera { }, image { width, height } {
    
}

Renderer::Renderer() : Renderer { 160, 45 } {

}


Canvas Renderer::renderGeneral(const Polygon& polygon) {
    image.clear();



    return image;
}

Canvas Renderer::renderClear(const Polygon& polygon) {
    image.clear();



    return image;
}


void Renderer::clearImage() {
    image.clear();
}

void Renderer::renderPoint(const Point& point) {
    
}

void Renderer::renderSegment(const Segment& segment) {
    Point start_point { segment.getStartPoint() };
    Point end_point { segment.getEndPoint() };
    Vector direction { segment.vector };
    
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