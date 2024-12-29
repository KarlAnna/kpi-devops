#include "ExponentialSeries.h"
#include <iostream>

ExponentialSeries::ExponentialSeries() {}

double ExponentialSeries::FuncA() {
    double sum = 1.0;
    double term = 1.0;
    double x = 1.0;
    
    for (int i = 1; i <= 1; ++i) {
        term = term * x / i;
        sum += term;
    }
    return 0;
}
