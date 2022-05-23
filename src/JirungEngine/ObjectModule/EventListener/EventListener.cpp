#include "EventListener.hpp"

#include "../Object.hpp"

using namespace std;
using namespace JirungEngine;


Condition EventListener::getEvent() {
    return condition;
}

void EventListener::collisionCheck() {
    for(Object* e : Object::object_list) {
        Condition current_condition = Condition::None;
        for(Object* other : Object::object_list) {
            if(e == other) {
                continue;
            }
            if(e->isCollidingWith(*other)) {
                current_condition = Condition::Collide;
            }
        }
        e->event_listener.condition = current_condition;
    }
}