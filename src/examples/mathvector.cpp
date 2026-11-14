#include "math.hpp"
#include "../gonlib/gonmathvector.hpp"
#include <iostream>

void exa_mathvector() {
    {
        gon::m::vec2 vec(1.0, 2.0);
        std::cout << "vec2d.x: " << vec.x << " vec2d.y: " << vec.y << std::endl;
        std::cout << "vec2d*{2.0, 3.0} dot:" << gon::vector2d::dot(vec, {2.0, 3.0}) << std::endl;
        std::cout << "vec2d*{2.0, 3.0} cross:" << gon::vector2d::cross(vec, {2.0, 3.0}) << std::endl;
        std::cout << "vec2d*{2.0, 3.0} hadamard:" << decltype(vec)::hadamard(vec, {2.0, 3.0}).x << ", " << decltype(vec)::hadamard(vec, {2.0, 3.0}).y << std::endl;
        std::cout << "vec2d near lenth:" << vec.near_length() << std::endl;
        std::cout << "vec2d lenth:" << vec.length() << std::endl;
        std::cout << "vec2d normalize:" << vec.normalize().x << ", " << vec.normalize().y << std::endl;
    }
    {
        gon::m::vec3 vec(1.0, 2.0, 3.0);
        std::cout << "vec3d.x: " << vec.x << " vec3d.y: " << vec.y << " vec3d.z: " << vec.z << std::endl;
        std::cout << "vec3d*{2.0, 3.0, 5.0} dot:" << decltype(vec)::dot(vec, {2.0, 3.0, 5.0}) << std::endl;
        std::cout << "vec3d*{2.0, 3.0, 5.0} cross:" << decltype(vec)::cross(vec, {2.0, 3.0, 5.0}).x << ", " << decltype(vec)::cross(vec, {2.0, 3.0, 5.0}).y << ", " << decltype(vec)::cross(vec, {2.0, 3.0, 5.0}).z << std::endl;
        std::cout << "vec3d*{2.0, 3.0, 5.0} hadamard:" << decltype(vec)::hadamard(vec, {2.0, 3.0, 5.0}).x << ", " << decltype(vec)::hadamard(vec, {2.0, 3.0, 5.0}).y << std::endl;
        std::cout << "vec3d near lenth:" << vec.near_length() << std::endl;
        std::cout << "vec3d lenth:" << vec.length() << std::endl;
        std::cout << "vec3d normalize:" << vec.normalize().x << ", " << vec.normalize().y << std::endl;
    }
    return;
}