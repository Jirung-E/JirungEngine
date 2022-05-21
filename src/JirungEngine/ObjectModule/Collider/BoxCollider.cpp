#include "BoxCollider.hpp"

using namespace JirungEngine;


BoxCollider::BoxCollider(const Point& top_left, const Point& bottom_right) : 
    top_left { top_left }, top_right { Point(bottom_right.x, top_left.y) }, bottom_right { bottom_right }, bottom_left { Point(top_left.x, bottom_right.y) }, 
    side {
        Collider { top_left, Vector(bottom_right.x - top_left.x, 0) }, 
        Collider { Point(bottom_right.x, top_left.y), Vector(0, bottom_right.y - top_left.y) }, 
        Collider { bottom_right, Vector(top_left.x - bottom_right.x, 0) }, 
        Collider { Point(top_left.x, bottom_right.y), Vector(0, top_left.y - bottom_right.y) }
    } {
    
}

BoxCollider::BoxCollider(const BoxCollider& box_collider) : BoxCollider { box_collider.top_left, box_collider.bottom_right } {
    
}


Collider BoxCollider::getTopSide() const {
    return side[0];
}

Collider BoxCollider::getRightSide() const {
    return side[1];
}

Collider BoxCollider::getBottomSide() const {
    return side[2];
}

Collider BoxCollider::getLeftSide() const {
    return side[3];
}

Point BoxCollider::getTopLeftPoint() const {
    return top_left;
}

Point BoxCollider::getTopRightPoint() const {
    return top_right;
}

Point BoxCollider::getBottomRightPoint() const {
    return bottom_right;
}

Point BoxCollider::getBottomLeftPoint() const {
    return bottom_left;
}

void BoxCollider::setTopLeftPoint(const Point& point) {
    top_left = point;
    side[3] = Collider { getBottomLeftPoint(), Vector(point.x - getBottomLeftPoint().x, point.y - getBottomLeftPoint().y) };
    side[0] = Collider { top_left, Vector(getTopRightPoint().x - point.x, getTopRightPoint().y - point.x) };
}

void BoxCollider::setTopRightPoint(const Point& point) {
    top_right = point;
    side[0] = Collider { getTopLeftPoint(), Vector(point.x - getTopLeftPoint().x, point.y - getTopLeftPoint().y) };
    side[1] = Collider { point, Vector(getBottomRightPoint().x - point.x, getBottomRightPoint().y - point.x) };
}

void BoxCollider::setBottomRightPoint(const Point& point) {
    bottom_right = point;
    side[1] = Collider { getTopRightPoint(), Vector(point.x - getTopRightPoint().x, point.y - getTopRightPoint().y) };
    side[2] = Collider { bottom_right, Vector(getBottomLeftPoint().x - point.x, getBottomLeftPoint().y - point.x) };
}

void BoxCollider::setBottomLeftPoint(const Point& point) {
    bottom_left = point;
    side[2] = Collider { getBottomRightPoint(), Vector(point.x - getBottomRightPoint().x, point.y - getBottomRightPoint().y) };
    side[3] = Collider { point, Vector(getTopLeftPoint().x - point.x, getTopLeftPoint().y - point.y) };
}