#include "BoxCollider.hpp"

using namespace JirungEngine;


BoxCollider::BoxCollider() : top_left { 0, 0 }, buttom_right { 0, 0 } {

}

BoxCollider::BoxCollider(const Point& top_left, const Point& buttom_right) : top_left { top_left }, buttom_right { buttom_right } {

}