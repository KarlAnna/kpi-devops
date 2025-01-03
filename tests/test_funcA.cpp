#include "../ExponentialSeries.h"
#include <iostream>
#include <cmath>
#include <cassert>

int main() {
    ExponentialSeries expSeries;

    // Test FuncA with 3 terms
    double result = expSeries.FuncA(3);
    double expected = 2.66666666667;
    double tolerance = 1e-5;

    assert(std::abs(result - expected) < tolerance && "FuncA(3) test failed!");

    std::cout << "Test passed for FuncA(3)" << std::endl;
    return 0;
}
