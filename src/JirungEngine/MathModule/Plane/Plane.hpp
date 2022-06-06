#ifndef __Plane_hpp__
#define __Plane_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"
#include "../Line/Line.hpp"


namespace JirungEngine {
    class Plane {
    public:
        Point point;
        Vector normal_vector;
        
    public:
        Plane(Point point = { 0, 0, 0 }, Vector normal_vector = { 0, 0, 1 });
        Plane(Vector normal_vector);
        
    public:
        bool isContactWith(const Point& point) const;
        Point* getPointOfContactWith(const Line& line) const;
        Point getFootOfPerpendicularFrom(const Point& point) const;
        float getDistanceTo(const Point& point) const;
        float getDistanceTo(const Line& line) const;
        float getDistanceTo(const Plane& other) const;
        bool isParallelTo(const Line& line) const;
        bool isParallelTo(const Plane& other) const;

        static Plane xy();
        static Plane xz();
        static Plane yz();
    };
}

#endif