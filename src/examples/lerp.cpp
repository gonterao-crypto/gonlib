#include "block.hpp"
#include "../gonlib/gonlerp.hpp"
#include <iostream>

void exa_lerp() {
    std::cout << "lerp: " << gon::lerp(0.0f, 1.0f, 0.5f) << std::endl;
    return;
}