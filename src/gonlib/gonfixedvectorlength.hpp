#pragma once
#include "gonmemory.hpp"
#include "gonexception.hpp"
#include "goniteratortemplate.hpp"

namespace gon {
    template <typename T, int N>
    class fixedvector {
        public:
            fixedvector() : nsize(0), lastaccesindex(-1), data() {
            }


            
            T& operator[] (int j) {
                if (N <= j || j < 0) {
                    lastaccesindex = j;
                    throw gon::out_of_range("gon::fixedvector outofrange");
                }
                return data[j];
            }
            T operator[] (int j) const {
                if (N <= j || j < 0) {
                    lastaccesindex = j;
                    throw gon::out_of_range("gon::fixedvector outofrange");
                }
                return data[j];
            }
            void push_back(const T& h) {
                if (nsize > N) {
                    lastaccesindex = nsize;
                    throw gon::out_of_range("gon::fixedvector outofrange");
                    return;
                }
                data[nsize] = h;
                ++nsize;
            }
            void pop_back() {
                --nsize;
            }
            T& back() {
                return data[nsize - 1];
            }
            ~fixedvector() {
                delete[] data;
            }
            size_t size() {
                return nsize;
            }
            constexpr size_t capacity() {
                return N;
            }

            using iterator = base::iterator_base<T, fixedvector>;
            iterator begin() {
                iterator t(*this);
                return t;
            }
            iterator end() {
                iterator t(*this, nsize);
                return t;
            }
            int errlastaccesindex() {
                return lastaccesindex;
            }
        private:
            size_t nsize = 0;
            mutable int lastaccesindex = -1;
            T data[N];
    };
}