#pragma once
#include "gonmath.hpp"

namespace gon {
    namespace m {
        namespace base {
#pragma pack(push, 1)

            template <int L, typename T>
            struct vec;
            
            template <typename T>
            struct vec<2, T> {
                T x, y;
                using stype = vec<2, T>;

                vec() {
                    x = 0;
                    y = 0;
                }
                vec(T cx, T cy) {
                    x = cx;
                    y = cy;
                }

                ~vec() = default;

                friend stype operator+(const stype& a, const stype& b) {
                    return stype(a.x + b.x, a.y + b.y);
                }
                friend stype operator-(const stype& a, const stype& b) {
                    return stype(a.x - b.x, a.y - b.y);
                }
                friend stype operator*(const stype& a, T b) {
                    stype c(a.x, a.y);
                    c.x *= b;
                    c.y *= b;
                    return c;
                }
                friend stype operator*(T a, const stype& b) {
                    return b * a;
                }
                static T dot(const stype& a, const stype& b) {
                    return a.x * b.x + a.y * b.y;
                }
                static T cross(const stype& a, const stype& b) {
                    return a.x * b.y - a.y * b.x;
                }
                static stype hadamard(const stype& a, const stype& b) {
                    return {a.x * b.x, a.y * b.y};
                }
                T near_length() {
                    return (x * x) + (y * y);
                }
                T length() {
                    return gon::sqrt(near_length());
                }
                stype normalize() {
                    T leng = length();
                    if (leng == 0) {
                        return {x, y};
                    }
                    return {x / leng, y / leng};
                }
            };

            template <typename T>
            struct vec<3, T> {
                T x, y, z;

                using stype = vec<3, T>;

                vec() {
                    x = 0;
                    y = 0;
                    z = 0;
                }
                vec(T cx, T cy, T cz) {
                    x = cx;
                    y = cy;
                    z = cz;
                }

                ~vec() = default;

                friend stype operator+(const stype& a, const stype& b) {
                    return stype(a.x + b.x, a.y + b.y, a.z + b.z);
                }
                friend stype operator-(const stype& a, const stype& b) {
                    return stype(a.x - b.x, a.y - b.y, a.z - b.z);
                }
                friend stype operator*(const stype& a, T b) {
                    stype c(a.x, a.y, a.z);
                    c.x *= b;
                    c.y *= b;
                    c.z *= b;
                    return c;
                }
                friend stype operator*(T a, const stype& b) {
                    return b * a;
                }
                static T dot(const stype& a, const stype& b) {
                    return a.x * b.x + a.y * b.y + a.z * b.z;
                }
                static stype cross(const stype& a, const stype& b) {
                    return {
                        a.y * b.z - a.z * b.y,
                        a.z * b.x - a.x * b.z,
                        a.x * b.y - a.y * b.x
                    };
                }
                static stype hadamard(const stype& a, const stype& b) {
                    return {a.x * b.x, a.y * b.y, a.z * b.z};
                }
                T near_length() {
                    return (x * x) + (y * y) + (z * z);
                }
                T length() {
                    return gon::sqrt(near_length());
                }
                stype normalize() {
                    T leng = length();
                    if (leng == 0) {
                        return {x, y, z};
                    }
                    return {x / leng, y / leng, z / leng};
                }
            };

            template <typename T>
            struct vec<4, T> {
                T x, y, z, w;

                using stype = vec<4, T>;

                vec() {
                    x = 0;
                    y = 0;
                    z = 0;
                    w = 0;
                }
                vec(T cx, T cy, T cz, T cw) {
                    x = cx;
                    y = cy;
                    z = cz;
                    w = cw;
                }

                ~vec() = default;

                friend stype operator+(const stype& a, const stype& b) {
                    return stype(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
                }
                friend stype operator-(const stype& a, const stype& b) {
                    return stype(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
                }
                friend stype operator*(const stype& a, T b) {
                    stype c(a.x, a.y, a.z);
                    c.x *= b;
                    c.y *= b;
                    c.z *= b;
                    c.w *= b;
                    return c;
                }
                friend stype operator*(T a, const stype& b) {
                    return b * a;
                }
                static T dot(const stype& a, const stype& b) {
                    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
                }
                static stype hadamard(const stype& a, const stype& b) {
                    return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
                }
                T near_length() {
                    return (x * x) + (y * y) + (z * z) + (w * w);
                }
                T length() {
                    return gon::sqrt(near_length());
                }
                stype normalize() {
                    T leng = length();
                    if (leng == 0) {
                        return {x, y, z};
                    }
                    return {x / leng, y / leng, z / leng, w / leng};
                }
#pragma pack(pop)
            };
        }
        using vec2 = base::vec<2, float>;
        using vec3 = base::vec<3, float>;
        using vec4 = base::vec<4, float>;

        using vec2d = base::vec<2, double>;
        using vec3d = base::vec<3, double>;
        using vec4d = base::vec<4, double>;
    }
}