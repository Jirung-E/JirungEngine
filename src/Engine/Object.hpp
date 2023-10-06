#ifndef __Object_hpp__
#define __Object_hpp__

#include "../Math/Geometry.hpp"
#include "../Math/Polygon.hpp"
#include "Physics.hpp"

#include <vector>


namespace Engine {
    class Object : public Math::Geometry {
    public:
        std::vector<Math::Polygon*> polygons;
        Physics physics;
        
    public:
        Object();
        ~Object();
        
    public:
        void addPolygon(Math::Polygon* polygon, Math::Point point = { 0, 0, 0 });
        
        void rotateX(float radian);
        void rotateY(float radian);
        void rotateZ(float radian);
        void rotate(const Math::Line& axis, float radian);
        
        void moveTo(const Math::Point& point);
        
        void update();
    };
}

#endif