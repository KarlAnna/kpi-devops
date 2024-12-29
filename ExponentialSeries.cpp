#include "ExponentialSeries.h"
#include <iostream>

ExponentialSeries::ExponentialSeries(int n) {}

double ExponentialSeries::FuncA() {
    double sum = 1.0;
    double term = 1.0;
    double x = 1.0;
    
    for (int i = 1; i <= n; ++i) {
        term = term * x / i;
        sum += term;
    }
    return sum;
}
