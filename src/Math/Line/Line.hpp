#ifndef __Line_hpp__
#define __Line_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"


namespace Math {
    class Line {
    public:
        Point point;
        Vector vector;
        
    public:
        Line(Point point, Vector vector);
        Line(Vector vector);

    public:
        bool isExistPointOfContactWith(const Line& other) const;
        Point* getPointOfContactWith(const Line& other) const;
        Point getFootOfPerpendicularFrom(const Point& point) const;
        Point getFootOfPerpendicularFrom(const Line& line) const;
        float getDistanceTo(const Point& point) const;
        float getDistanceTo(const Line& other) const;
        bool isParallelTo(const Line& other) const;

        static float getDistanceBetween(const Point& point, const Line& line);
        static float getDistanceBetween(const Line& line, const Point& point);
        static float getDistanceBetween(const Line& line1, const Line& line2);
        static Line getNormalOf(const Line& line1, const Line& line2);
        static bool isParallel(const Line& line1, const Line& line2);
        static Point getFootOfPerpendicular(const Line& line, const Point& point);
        static Point getFootOfPerpendicular(const Line& to, const Line& from);
        
        static Point rotate(const Point& point, const Line& axis, float radian);
    };
}

#endif