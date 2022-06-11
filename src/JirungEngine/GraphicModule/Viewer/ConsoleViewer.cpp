#include "ConsoleViewer.hpp"

#include "../../../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


void ConsoleViewer::show(const Canvas& canvas) {
    println(canvas.getByString());
}