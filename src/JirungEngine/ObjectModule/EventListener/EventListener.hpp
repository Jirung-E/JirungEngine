#ifndef __EventListener_hpp__
#define __EventListener_hpp__

namespace JirungEngine {
    enum class Condition {
        None, Collide, 
    };
    
    class EventListener {
    public:
        Condition condition;
    
    public:
        Condition getEvent();
        static void collisionCheck();
    };
}

#endif