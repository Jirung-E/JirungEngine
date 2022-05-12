#ifndef __Point_hpp__
#define __Point_hpp__

namespace JirungEngine {
    class Point {
        public: int x;
        public: int y;
        public: int z;

    public:
        Point();
        Point(int x, int y, int z = 0);
        Point(const Point& point);

        Point operator=(const Point& point);
        Point operator+(const Point& point);
        Point operator-(const Point& point);
        Point operator*(int n);
        Point operator/(int n);
    };
}

#endif