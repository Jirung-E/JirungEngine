#include "Logger.hpp"

#include "../../Util/Util.hpp"

using namespace Util;
using namespace JirungEngine;


bool Logger::show_log = false;

void Logger::log(str_t str) {
    if(show_log == true) {
        println("log: " + str);
    }
}