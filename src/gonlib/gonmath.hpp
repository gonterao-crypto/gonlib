#pragma once

namespace gon {
    float sqrt(float value);
    double sqrt(double value);
    
    double abs(double value);
    int abs(int value);
    long abs(long value);
    long long abs(long long value);
    float abs(float value);
    short abs(short value);
    char abs(char value);

    template <typename T>
    class vector2d_t {
        public:
            T x = 0;
            T y = 0;
            vector2d_t operator-() const {
                return vector2d_t(-x, -y);
            }
            
            vector2d_t(T ix, T iy) {
                x = ix;
                y = iy;
            }
            friend vector2d_t operator+(const vector2d_t& a, const vector2d_t& b) {
                return vector2d_t(a.x + b.x, a.y + b.y);
            }
            friend vector2d_t operator-(const vector2d_t& a, const vector2d_t& b) {
                return vector2d_t(a.x - b.x, a.y - b.y);
            }
            friend vector2d_t operator*(const vector2d_t& a, int b) {
                vector2d_t c(a.x, a.y);
                c.x *= b;
                c.y *= b;
                return c;
            }
            friend vector2d_t operator*(int a, const vector2d_t& b) {
                return b * a;
            }
            static T dot(const vector2d_t& a, const vector2d_t& b) {
                return a.x * b.x + a.y * b.y;
            }
            static T cross(const vector2d_t& a, const vector2d_t& b) {
                return a.x * b.y - a.y * b.x;
            }
            static vector2d_t hadamard(const vector2d_t& a, const vector2d_t& b) {
                return {a.x * b.x, a.y * b.y};
            }
            T near_length() {
                return (x * x) + (y * y);
            }
            T length() {
                return sqrt(near_length());
            }
            vector2d_t normalize() {
                T leng = length();
                if (leng == 0) {
                    return {x, y};
                }
                return {x / leng, y / leng};
            }
        private:
    };
    using vector2d = vector2d_t<double>;
    using vector2df = vector2d_t<float>;
}