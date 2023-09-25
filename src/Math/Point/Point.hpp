#ifndef __Point_hpp__
#define __Point_hpp__

namespace Math {
    class Vector;
    
    class Point {
    public:
        float x;
        float y;
        float z;
        
    public:
        Point(float x, float y, float z = 0.0f);
        Point();
        Point(const Point& point);
        Point(const Vector& vector);

        Point operator=(const Point& point);
        Point operator+(const Point& point) const;
        Point operator*(float n) const;
        Point operator/(float n) const;
        bool operator==(const Point& point) const;
        bool operator!=(const Point& point) const;
        Point operator+=(const Point& point);
        Point operator*=(float n);
        Point operator/=(float n);

        bool isInRange(const Point& point1, const Point& point2) const;
        
        float getDistanceTo(const Point& other) const;
        static float getDistanceBetween(const Point& point1, const Point& point2);

        static Point origin();
    };
}

#endif