#include "Collider.hpp"

using namespace JirungEngine;


Collider::Collider(const Point& start_point, const Vector& vector) : start_point { start_point }, vector { vector } {
    
}

Collider::Collider(const Collider& new_collider) : start_point { new_collider.start_point }, vector { new_collider.vector } {
    
}


bool Collider::isCollidingWith(const Collider& other) const {
    auto x = [&start_point, &vector](float t) { return start_point.x + vector.x*t; };       // 0 <= t <= 1
    auto y = [&start_point, &vector](float t) { return start_point.y + vector.y*t; };
    auto z = [&start_point, &vector](float t) { return start_point.z + vector.z*t; };

    auto other_x = [&other](float t) { return other.start_point.x + other.vector.x*t; };
    auto other_y = [&other](float t) { return other.start_point.y + other.vector.y*t; };
    auto other_z = [&other](float t) { return other.start_point.z + other.vector.z*t; };

    // x == other_x 인 t;
    // start_point.x - other.start_point.x + (vector.x - other.vector.x) * t == 0;
    // t == -((start_point.x - other.start_point.x) / (vector.x - other.vector.x));
    // 이거다 ㅋㅋ

    // t = (x-x0)/a;
}

// A(1, 2, 4) <4, 5, 6>
// B(-1, 4, 2) <7, -2, 1>

// LA :	x = 1 + 4t,     y = 2 + 5t,     z = 4 + 6t
// LB :	x = -1 + 7t,    y = 4 - 2t,     z = 2 + t

// t의 값이 다르므로 접선 x

//      t = (x-1)/4,    t = (y-2)/5,    t = (z-4)/6
//      t = (x+1)/7,	t = -(y-4)/2,   t = z-2

// 28t = 7(x-1)
// 28t = 4(x+1)
// 0 = 3x - 11, x = 11/3;
// ...

Point Collider::getEndPoint() const {
    return Point { start_point.x + vector.x, start_point.y + vector.y, start_point.z + vector.z };
}

// float Collider::x(float float_in_range_of_0_to_1) const {
//     return start_point.x + vector.x*t;
// }