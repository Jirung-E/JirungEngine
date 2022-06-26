#ifndef __Input_h__
#define __Input_h__

#include <termios.h>


namespace IO {
    enum class KeyID {
        UNKNOWN = -1, NONE = 0, ESC = 27, SPACE = 32, ENTER = 10, BACKSPACE = 127, TAB = 9, 
    };
    
    enum class KeyState {
        UP, DOWN
    };
    
    
    class KeyboardListener {
    private:
        static struct termios oldt;
        
        KeyID recent_input;
        
    public:
        void inputModeOn();
        void inputModeOff();
        
        KeyID getPressedKeyId();
        bool detectKeyPress();
        
        bool getKeyDown(KeyID id);
        bool getKeyDownNow(KeyID id);
        bool getKeyUpNow(KeyID id);
        
        KeyState getCurrentKeyState(KeyID id);
    };
    
    class Key {
    public:
        static KeyState getState(KeyID id);
    };
}

#endif