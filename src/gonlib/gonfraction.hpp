#pragma once

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

                T getnumver() {
                    return numer;
                }
                T getdenom() {
                    return denom;
                }
            private:
                T numer = 1; //子
                T denom = 1; //母
        };
    }
    using fraction = base::fraction_base<int>;
}