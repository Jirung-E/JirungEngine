#include "Util.hpp"

using namespace Util;


void Util::print(str_t str) {
    printf("%s", str.c_str());
}

void Util::println(str_t str) {
    printf("%s\n", str.c_str());
}