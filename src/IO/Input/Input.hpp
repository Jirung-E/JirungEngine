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
        
        int recent_input;
        
    public:
        void inputModeOn();
        void inputModeOff();
        
        KeyID getInput();
        bool detectKeyPress();
        
        int getPressedKeyID();
    };
}

#endif