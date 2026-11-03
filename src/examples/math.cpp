#include "math.hpp"
#include "../gonlib/gonmath.hpp"
#include <iostream>

void exa_math() {
    std::cout << "10.0f sqrt: " << gon::sqrt(10.0f) << std::endl;
    gon::vector2d vec(1.0, 2.0);
    std::cout << "vec2d.x: " << vec.x << " vec2d.y: " << vec.y << std::endl;
    std::cout << "vec2d*{2.0, 3.0} dot:" << gon::vector2d::dot(vec, {2.0, 3.0}) << std::endl;
    std::cout << "vec2d*{2.0, 3.0} cross:" << gon::vector2d::cross(vec, {2.0, 3.0}) << std::endl;
    std::cout << "vec2d*{2.0, 3.0} hadamard:" << decltype(vec)::hadamard(vec, {2.0, 3.0}).x << ", " << decltype(vec)::hadamard(vec, {2.0, 3.0}).y << std::endl;
    std::cout << "vec2d near lenth:" << vec.near_length() << std::endl;
    std::cout << "vec2d lenth:" << vec.length() << std::endl;
    std::cout << "vec2d normalize:" << vec.normalize().x << ", " << vec.normalize().y << std::endl;
    return;
}