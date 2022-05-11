#include "Util.hpp"

using namespace Util;


void util::print(str_t str) {
    printf("%s", str.c_str());
}

void util::println(str_t str) {
    printf("%s\n", str.c_str());
}