#include "gonmath.hpp"

namespace gon {
    float sqrt(float value) { 
        return __builtin_sqrt(value);
    }
    double sqrt(double value) {  
        return __builtin_sqrt(value);
    }
}