#include "gonmath.hpp"

namespace gon {
    float sqrt(float value) { 
        return __builtin_sqrtf(value);
    }
    double sqrt(double value) {  
        return __builtin_sqrt(value);
    }
    double abs(double value) { return value < 0 ? -value : value; }
    int abs(int value) { return value < 0 ? -value : value; }
    long abs(long value) { return value < 0 ? -value : value; }
    long long abs(long long value) { return value < 0 ? -value : value; }
    float abs(float value) { return value < 0 ? -value : value; }
    short abs(short value) { return value < 0 ? -value : value; }
    char abs(char value) { return value < 0 ? -value : value; }
}