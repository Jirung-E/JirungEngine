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
                for(Collider other_c : other->collider)
                if(c.isCollidingWith(other_c)) {
                    
                }
                else {
                    
                }
            }
        }
    }
}