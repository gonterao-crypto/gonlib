#pragma once

namespace gon {
    namespace base {
        template <typename T, typename G>
        class iterator_base {
            public:
                iterator_base(G& j) : index(0), n(j) { }
                iterator_base(G& j, int inde) : index(inde), n(j) { }
                ~iterator_base() { }
                iterator_base &operator++() {
                    ++index;
                    return *this;
                }
                iterator_base &operator--() {
                    --index;
                    return *this;
                }
                T& operator *() {
                    return n[index];
                }
                const T& operator *() const {
                    return n[index];
                }
                bool operator !=(const iterator_base &rhs) const {
                    return index != rhs.index;
                }
            private:
                int index = 0;
                G& n;
        };
    }
}