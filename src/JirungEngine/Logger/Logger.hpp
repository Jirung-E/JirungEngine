#ifndef __Logger_hpp__
#define __Logger_hpp__

#include "../../Util/UtilType.hpp"


namespace JirungEngine {   
    class Logger {
        public: static bool show_log;

    public:
        static void log(util::str_t str);
    };
}

#endif