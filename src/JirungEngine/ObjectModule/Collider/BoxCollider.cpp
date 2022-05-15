#include "BoxCollider.hpp"

using namespace JirungEngine;


BoxCollider::BoxCollider(const Point& top_left, const Point& buttom_right) : 
    top_left { top_left }, top_right { Point(buttom_right.x, top_left.y) }, buttom_right { buttom_right }, buttom_left { Point(top_left.x, buttom_right.y) }, 
    side {
        Collider { top_left, Vector2D(buttom_right.x - top_left.x, 0) }, 
        Collider { Point(buttom_right.x, top_left.y), Vector2D(0, buttom_right.y - top_left.y) }, 
        Collider { buttom_right, Vector2D(top_left.x - buttom_right.x, 0) }, 
        Collider { Point(top_left.x, buttom_right.y), Vector2D(0, top_left.y - buttom_right.y) }
    } {
    
}

BoxCollider::BoxCollider(const BoxCollider& box_collider) : BoxCollider { box_collider.top_left, box_collider.buttom_right } {
    
}


Collider BoxCollider::getTopSide() const {
    return side[0];
}

Collider BoxCollider::getRightSide() const {
    return side[1];
}

Collider BoxCollider::getButtomSide() const {
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

Point BoxCollider::getButtomRightPoint() const {
    return buttom_right;
}

Point BoxCollider::getButtomLeftPoint() const {
    return buttom_left;
}

void BoxCollider::setTopLeftPoint(const Point& point) {
    top_left = point;
    side[3] = Collider { getButtomLeftPoint(), Vector2D(point.x - getButtomLeftPoint().x, point.y - getButtomLeftPoint().y) };
    side[0] = Collider { top_left, Vector2D(getTopRightPoint().x - point.x, getTopRightPoint().y - point.x) };
}

void BoxCollider::setTopRightPoint(const Point& point) {
    top_right = point;
    side[0] = Collider { getTopLeftPoint(), Vector2D(point.x - getTopLeftPoint().x, point.y - getTopLeftPoint().y) };
    side[1] = Collider { point, Vector2D(getButtomRightPoint().x - point.x, getButtomRightPoint().y - point.x) };
}

void BoxCollider::setButtomRightPoint(const Point& point) {
    buttom_right = point;
    side[1] = Collider { getTopRightPoint(), Vector2D(point.x - getTopRightPoint().x, point.y - getTopRightPoint().y) };
    side[2] = Collider { buttom_right, Vector2D(getButtomLeftPoint().x - point.x, getButtomLeftPoint().y - point.x) };
}

void BoxCollider::setButtomLeftPoint(const Point& point) {
    buttom_left = point;
    side[2] = Collider { getButtomRightPoint(), Vector2D(point.x - getButtomRightPoint().x, point.y - getButtomRightPoint().y) };
    side[3] = Collider { point, Vector2D(getTopLeftPoint().x - point.x, getTopLeftPoint().y - point.y) };
}