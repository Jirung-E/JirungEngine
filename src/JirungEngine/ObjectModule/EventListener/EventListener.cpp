#include "EventListener.hpp"

#include "../Object.hpp"

using namespace std;
using namespace JirungEngine;


Condition EventListener::getEvent() {
    collisionCheck();
    return condition;
}

void EventListener::collisionCheck() {
    for(Object* e : Object::object_list) {
        for(Object* other : Object::object_list) {
            if(e == other) {
                continue;
            }
            if(e->isCollidingWith(*other)) {
                e->event_listener.condition = Condition::Collide;
            }
            else {
                e->event_listener.condition = Condition::None;
            }
        }
    }
}