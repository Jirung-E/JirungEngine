#ifndef __Point_hpp__
#define __Point_hpp__

namespace Math {
    class Point {
    public:
        float x;
        float y;
        float z;
        
    public:
        Point(float x, float y, float z = 0.0f);
        Point();
        Point(const Point& point);
    };
}

#endif