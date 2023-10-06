#include "Test/ThreadTest.h"
#include "Test/RenderingTest.h"

#include "IO/Input.hpp"
#include "IO/ConsoleManager.hpp"
#include "IO/Test/test.h"

#include "Math/Test/test.h"


void IO_test() {
    testGetInput();
    testDetectKeyPress();
    testGetInputByAnotherThread();
    IO::test();
}

void Math_test() {
    Math::test();
}


int main() {
    //testThread();
    RenderingTest::test();
}