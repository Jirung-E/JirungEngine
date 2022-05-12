#include "BoxCollider.hpp"

using namespace JirungEngine;


BoxCollider::BoxCollider(const Point& top_left, const Point& buttom_right) : top_left { top_left }, buttom_right { buttom_right }, 
                             side { 
                                 { top_left, Vector2D(buttom_right.x - top_left.x, 0), nullptr }, 
                                 { Point(buttom_right.x, top_left.y), Vector2D(0, buttom_right.y - top_left.y), nullptr }, 
                                 { buttom_right, Vector2D(top_left.x - buttom_right.x, 0), nullptr }, 
                                 { Point(top_left.x, buttom_right.y), Vector2D(0, top_left.y - buttom_right.y), nullptr } } {

}