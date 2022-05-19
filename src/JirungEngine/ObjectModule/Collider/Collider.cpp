#include "Collider.hpp"

using namespace JirungEngine;


Collider::Collider(const Point& start_point, const Vector& vector) : start_point { start_point }, vector { vector } {
    
}

Collider::Collider(const Collider& new_collider) : start_point { new_collider.start_point }, vector { new_collider.vector } {
    
}


bool Collider::isCollidingWith(const Collider& other) const {
    float t;
    this->line().x(t) == other.line().x(t);

    // (x - start_point.x) / vector.x == (y - start_point.y) / vector.y

    // t = (x-x0)/a;
}

// A(1, 2, 4) <4, 5, 6>
// B(-1, 4, 2) <7, -2, 1>

// LA :	x = 1 + 4t,     y = 2 + 5t,     z = 4 + 6t
// LB :	x = -1 + 7t,    y = 4 - 2t,     z = 2 + t

// t의 값이 다르므로 접선 없음.

//      t = (x-1)/4,    t = (y-2)/5,    t = (z-4)/6
//      t = (x+1)/7,	t = -(y-4)/2,   t = z-2

// 28t = 7(x-1)
// 28t = 4(x+1)
// 0 = 3x - 11, x = 11/3;
// ...
// 4t = x-1
// 7t = x+1
// -> 3t = 2, t = 2/3
// x를 소거해야함. 같은 방식으로 y, z도 계산 후 값 비교해보면 될듯.

Point Collider::getEndPoint() const {
    return Point { start_point.x + vector.x, start_point.y + vector.y, start_point.z + vector.z };
}

// float Collider::x(float float_in_range_of_0_to_1) const {
//     return start_point.x + vector.x*t;
// }

Segment Collider::line() const {
    return Segment { start_point, vector };
}