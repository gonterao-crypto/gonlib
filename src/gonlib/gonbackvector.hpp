#pragma once
#include "gonmemory.hpp"
#include "gonutils.hpp"

namespace gon {
    template<typename T>
    class backvector {
        public:
            backvector() : inpe(nullptr), nsize(0), reverse_size(0) {
                inpe = (T*)(gon::calloc(1, sizeof(T)));
                reverse_size = sizeof(T);
            }
            T& push_back(const T& n) {
                size_t hituyosize = ((nsize + 1) * sizeof(T));
                if (reverse_size < hituyosize) {
                    reverse_size *= 2;
                    T* cop = (T*)gon::calloc(1, reverse_size);
                    for (size_t i = 0; i < nsize; ++i) {
                        new (&cop[i]) T(move(inpe[i]));
                        inpe[i].~T();
                    }
                    gon::free(inpe);
                    inpe = cop;
                }
                ++nsize;
                new (&inpe[nsize - 1]) T(n);
                return inpe[nsize - 1];
            }
            void pop_back() {
                --nsize;
                inpe[nsize].~T();
                return;
            }
            T& back() {
                return inpe[nsize - 1];
            }
            T& operator[] (int n) {
                return inpe[n];
            }
            T operator[] (int n) const {
                return inpe[n];
            }
            ~backvector() {
                for (size_t i = 0; i < nsize; ++i) {
                    inpe[i].~T();
                }
                free((void*)inpe);
                inpe = nullptr;
                nsize = 0;
            }
            size_t size() {
                return nsize;
            }
            size_t r_size() {
                return reverse_size / sizeof(T);
            }
        private:
            size_t nsize = 0;
            size_t reverse_size = 0;
            T* inpe;
    };
}