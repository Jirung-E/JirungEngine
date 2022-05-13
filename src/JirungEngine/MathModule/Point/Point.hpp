#ifndef __Point_hpp__
#define __Point_hpp__

namespace JirungEngine {
    class Point {
        public: float x;
        public: float y;
        public: float z;

    public:
        Point();
        Point(float x, float y, float z = 0);
        Point(const Point& point);

        Point operator=(const Point& point);
        Point operator+(const Point& point);
        Point operator-(const Point& point);
        Point operator*(float n);
        Point operator/(float n);
    };
}

#endif