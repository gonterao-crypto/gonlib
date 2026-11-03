#pragma once

namespace gon {
    float sqrt(float value);
    double sqrt(double value);

    class vector2d {
        public:
            vector2d(double ix, double iy);
            double x = 0;
            double y = 0;
            vector2d operator-() const {
                return vector2d(-x, -y);
            }
            friend vector2d operator+(const vector2d& a, const vector2d& b);
            friend vector2d operator-(const vector2d& a, const vector2d& b);
            friend vector2d operator*(const vector2d& a, int b);
            friend vector2d operator*(int a, const vector2d& b);
            static double dot(const vector2d& a, const vector2d& b);
            static double cross(const vector2d& a, const vector2d& b);
            static vector2d hadamard(const vector2d& a, const vector2d& b);
            double near_length();
            double length();
            vector2d normalize();
        private:
    };
}