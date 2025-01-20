#include "../ExponentialSeries.h"
#include <iostream>
#include <chrono>
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

    // Performance test for FuncA with a large number of iterations
    int n = 200000000; // Number of iterations for the performance test

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; ++i) {
        expSeries.FuncA(i % 10); // Use modulus to vary input slightly
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

    if (duration >= 10 && duration <= 30) {
        std::cout << "Performance test passed: Execution time is " << duration << " seconds (within range)." << std::endl;
    } else {
        std::cerr << "Performance test failed: Execution time is " << duration << " seconds (out of range)." << std::endl;
        return 1;
    }

    return 0;
}
