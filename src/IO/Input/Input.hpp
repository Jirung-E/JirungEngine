#ifndef __Input_h__
#define __Input_h__

namespace IO {
    enum class KeyID {
        UNKNOWN = -1, ESC = 27, SPACE = 32, ENTER = 10, BACKSPACE = 127, TAB = 9, 
    };
    
    class KeyboardListener {
    private:
        KeyID recent_input;
        
    public:
        KeyID getPressedKeyId();
        
        bool getKeyDown(KeyID id);
        bool getKeyPressed(KeyID id);
        bool getKeyUp(KeyID id);
    };
}

#endif