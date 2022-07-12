#ifndef __Input_h__
#define __Input_h__

#include <termios.h>


namespace IO {
    enum class KeyID {
        UNKNOWN = -1, NONE = 0, ESC = 27, SPACE = 32, ENTER = 10, BACKSPACE = 127, TAB = 9, 
    };
    
    
    class Input {
    public:
        virtual KeyID getInput() = 0;
        virtual bool detectKeyPress() = 0;
        
        virtual KeyID getPressedKeyID() = 0;
    };
    
    
    class KeyboardListener : public Input {
    private:
        struct termios oldt;
        
        KeyID recent_input;
        
    public:
        KeyboardListener();
        ~KeyboardListener();
        
    public:
        void inputModeOn();
        void inputModeOff();
        
        KeyID getInput();
        bool detectKeyPress();
        
        KeyID getPressedKeyID();
    };
}

#endif