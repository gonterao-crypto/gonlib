#include "gonmath.hpp"

namespace gon {
    float sqrt(float value) { 
        return __builtin_sqrt(value);
    }
    double sqrt(double value) {  
        return __builtin_sqrt(value);
    }
    vector2d::vector2d(double ix, double iy) {
        x = ix;
        y = iy;
    }
    vector2d operator+(const vector2d& a, const vector2d& b) {
        return vector2d(a.x + b.x, a.y + b.y);
    }
    vector2d operator-(const vector2d& a, const vector2d& b) {
        return vector2d(a.x - b.x, a.y - b.y);
    }
    vector2d operator*(const vector2d& a, int b) {
        vector2d c(a.x, a.y);
        c.x *= b;
        c.y *= b;
        return c;
    }
    vector2d operator*(int a, const vector2d& b) {
        return b * a;
    }
    double vector2d::dot(const vector2d& a, const vector2d& b) {
        return a.x * b.x + a.y * b.y;
    }
    double vector2d::cross(const vector2d& a, const vector2d& b) {
        return a.x * b.y - a.y * b.x;
    }
    vector2d vector2d::hadamard(const vector2d& a, const vector2d& b) {
        return {a.x * b.x, a.y * b.y};
    }
    double vector2d::near_length() {
        return (x * x) + (y * y);
    }
    double vector2d::length() {
        return sqrt(near_length());
    }
    vector2d vector2d::normalize() {
        double leng = length();
        if (leng == 0) {
            return {x, y};
        }
        return {x / leng, y / leng};
    }
}