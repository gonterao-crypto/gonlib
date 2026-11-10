#pragma once
#include "gonmath.hpp"

namespace gon {
    namespace base {
        template <typename T>
        class fraction_base {
            public:
                fraction_base() {
                    set(1, 1);
                }
                fraction_base(T n, T d) {
                    set(n, d);
                }
                fraction_base(const fraction_base& a) {
                    set(a);
                }
                ~fraction_base() = default;


                static T gcd(T a, T b) {
                    a = abs(a);
                    b = abs(b);
                    if (a < b) {
                        T t = b;
                        b = a;
                        a = t;
                    }
                    T tmp = 0;
                    while (b != 0) {
                        tmp = b;
                        b = a % b;
                        a = tmp;
                    }
                    return a;
                }
                static T lcm(T a, T b) {
                    a = abs(a);
                    b = abs(b);
                    if (a > b) {
                        T t = b;
                        b = a;
                        a = t;
                    }
                    if (a == 1) return b;

                    a = (a * b) / gcd(a, b);
                    return a;
                }


                void set(T n, T d) {
                    numer = n;
                    denom = d;
                }
                void set(const fraction_base& a) {
                    numer = a.numer;
                    denom = a.denom;
                }
                void setnumer(T n) {
                    numer = n;
                }
                void setdenom(T d) {
                    denom = d;
                }


                T getnumer() {
                    return numer;
                }
                T getdenom() {
                    return denom;
                }

                void signnormal() {
                    if (denom < 0) {
                        denom *= -1;
                        numer *= -1;
                    }
                    return;
                }
                void signnormal(T& num, T& den) {
                    if (den < 0) {
                        den *= -1;
                        num *= -1;
                    }
                    return;
                }

                void normal() {
                    T gc = gcd(numer, denom);
                    if (gc == 1) {
                        signnormal();
                    }
                    T num = numer / gc;
                    T den = denom / gc;
                    signnormal(num, den);
                    set(num, den);
                    return;
                }

                bool equals(const fraction_base& b) const {
                    return numer == b.numer && denom == b.denom;
                }
                T compre(const fraction_base& b) {
                    T lc = lcm(denom, b.denom);

                    return (lc / denom) * numer - (lc / b.denom) * b.numer;
                }

                friend const bool operator==(const fraction_base& a, const fraction_base& b) {
                    return a.equals(b);
                }
                friend const bool operator!=(const fraction_base& a, const fraction_base& b) {
                    return !a.equals(b);
                }
                friend const bool operator>=(const fraction_base& a, const fraction_base& b) {
                    return a.compre(b) >= 0;
                }
                friend const bool operator<=(const fraction_base& a, const fraction_base& b) {
                    return a.compre(b) <= 0;
                }
                friend const bool operator>(const fraction_base& a, const fraction_base& b) {
                    return a.compre(b) > 0;
                }
                friend const bool operator<(const fraction_base& a, const fraction_base& b) {
                    return a.compre(b) < 0;
                }

                fraction_base& operator=(const fraction_base& a) {
                    set(a);
                    return *this;
                }

                friend fraction_base operator+(const fraction_base& a, const fraction_base& b) {
                    T lc = fraction_base::lcm(a.denom, b.denom);
                    T num = a.numer * (lc / a.denom) + b.numer * (lc / b.denom);
                    return fraction_base(num, lc);
                }
                friend fraction_base operator-(const fraction_base& a, const fraction_base& b) {
                    return a + fraction_base(-b.numer, b.denom);
                }
                friend fraction_base operator*(const fraction_base& a, const fraction_base& b) {
                    T gc = fraction_base::gcd(a.numer, b.denom);
                    T num = a.numer / gc;
                    T den = b.denom / gc;

                    gc = fraction_base::gcd(a.numer, b.denom);
                    num *= b.numer / gc;
                    den *= a.denom / gc;

                    return fraction_base(num, den);
                }
                friend fraction_base operator/(const fraction_base& a, const fraction_base& b) {
                    return a * fraction_base(b.denom, b.numer);
                }

                fraction_base& operator+=(const fraction_base& a) {
                    return *this = *this + a;
                }
                fraction_base& operator-=(const fraction_base& a) {
                    return *this = *this - a;
                }
                fraction_base& operator*=(const fraction_base& a) {
                    return *this = *this * a;
                }
                fraction_base& operator/=(const fraction_base& a) {
                    return *this = *this / a;
                }

                fraction_base operator+() {
                    return fraction_base(numer, denom);
                }
                fraction_base operator-() {
                    return fraction_base(-numer, denom);
                }
                fraction_base& operator++() {
                    return *this + 1;
                }
                fraction_base& operator--() {
                    return *this - 1;
                }
                
                
                fraction_base operator++(int) {
                    fraction_base tmp = *this;
                    *this += 1;
                    return tmp;
                }
                fraction_base operator--(int) {
                    fraction_base tmp = *this;
                    *this -= 1;
                    return tmp;
                }

            private:
                T numer = 1; //子
                T denom = 1; //母
        }; // 参考：https://qiita.com/HitsujiRere/items/43a4b53c64b8eec3b7bd
    }
    using ffraction = base::fraction_base<float>;
    using dfraction = base::fraction_base<double>;
    using fraction = base::fraction_base<int>;
    using lfraction = base::fraction_base<long>;
    using cfraction = base::fraction_base<char>;
    using sfraction = base::fraction_base<short>;
    using llfraction = base::fraction_base<long long>;
}