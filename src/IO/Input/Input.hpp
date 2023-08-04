#ifndef __Input_h__
#define __Input_h__

#ifdef __linux__
#include <termios.h>
#endif


namespace IO {
    enum class KeyID {
        UNKNOWN = -1, NONE = 0, ESC = 27, SPACE = 32, ENTER = 10, BACKSPACE = 127, TAB = 9, 
#ifdef __linux__
        UPARROW = 183, DOWNARROW = 184, RIGHTARROW = 185, LEFTARROW = 186, 
        MODIFY = 91,
#endif
#ifdef _WIN32
        MODIFY = 224,
        UPARROW = 72 + MODIFY, LEFTARROW = 75 + MODIFY, RIGHTARROW = 77 + MODIFY, DOWNARROW = 80 + MODIFY,
#endif
        A = 97, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 
    };
    
    
    class Input {
    public:
        virtual KeyID getInput() = 0;
        virtual bool detectKeyPress() = 0;
        
        virtual KeyID getPressedKeyID() = 0;
    };
    
    
    class KeyboardListener : public Input {
    private:
#ifdef __linux__
        struct termios oldt;
#endif
        
        KeyID recent_input;
        
    public:
        KeyboardListener();
        ~KeyboardListener();
        
    private:
        int getChar();
        int getKey();
        
    public:
        void inputModeOn();
        void inputModeOff();
        
        KeyID getInput();
        bool detectKeyPress();
        
        KeyID getPressedKeyID();
    };
}

#endif