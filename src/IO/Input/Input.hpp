#ifndef __Input_h__
#define __Input_h__

namespace IO {
    class KeyboardListener {
    private:
        int recent_input;
        
    public:
        int getPressedKeyId();
        
        bool getKeyDown(int id);
        bool getKeyPressed(int id);
        bool getKeyUp(int id);
    };
}

#endif