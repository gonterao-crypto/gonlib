#include "gonmath.hpp"

namespace gon {
    float sqrt(float value) { 
        return __builtin_sqrtf(value);
    }
    double sqrt(double value) {  
        return __builtin_sqrt(value);
    }
}