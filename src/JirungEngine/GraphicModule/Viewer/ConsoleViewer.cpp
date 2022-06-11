#include "ConsoleViewer.hpp"

#include "../../../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


void ConsoleViewer::show(const Display& display) {
    println(display.getByString());
}