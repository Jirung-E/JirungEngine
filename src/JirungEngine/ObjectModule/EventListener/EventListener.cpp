#include "EventListener.hpp"

#include "../Object.hpp"

using namespace std;
using namespace JirungEngine;


void EventListener::collisionCheck() {
    for(Object* e : Object::object_list) {
        for(Object* other : Object::object_list) {
            if(e == other) {
                continue;
            }
            for(Collider c : e->collider) {
                if(c.isCollidingWith(*other)) {
                    
                }
                else {
                    
                }
            }
        }
    }
}