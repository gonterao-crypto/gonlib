#pragma once
#include "gonbackvector.hpp"

namespace gon {
    template<typename T>
    class blocks {
        public:
            blocks(int size) : blocksize(size), blockptrs() {
                block* b = new block(blocksize);
                blockptrs.push_back(b);
            }

            T& push_back(const T& y) {
                if (blockptrs.size() <= 0) {
                    block* b = new block(blocksize);
                    blockptrs.push_back(b);
                }
                block& f = *blockptrs[blockptrs.size() - 1];
                if (f.is_manpai()) {
                    block* b = new block(blocksize);
                    blockptrs.push_back(b);
                    blockptrs[blockptrs.size() - 1]->push_back(y);
                } else {
                    f.push_back(y);
                }
                ++nsize;
                return (*this)[nsize - 1];
            }

            void pop_back() {
                int n = nsize - 1;
                int blockc = (n / blocksize);
                block& k = (*blockptrs[blockc]);
                k.pop_back();
                if (k.umeta() == 0) {
                    delete blockptrs[blockc];
                    blockptrs[blockc] = nullptr;
                }
                --nsize;
                return;
            }

            size_t size() {
                return nsize;
            }

            size_t blockcount() {
                return blockptrs.size();
            }

            ~blocks() {
                for (int i = 0; i < blockptrs.size(); ++i) {
                    delete blockptrs[i];
                }
            }

            T& operator[] (int n) {
                int blockc = (n / blocksize);
                int blocko = (n % blocksize);
                return (*blockptrs[blockc])[blocko];
            }
            T operator[] (int n) const {
                int blockc = (n / blocksize);
                int blocko = (n % blocksize);
                return (*blockptrs[blockc])[blocko];
            }
        private:
            
            class block {
                public:
                    block(const int blocksize_v) : blocksize(blocksize_v), data(nullptr), ume(0) {
                        data = new T[blocksize];
                    }
                    ~block() {
                        delete[] data;
                    }

                    T& push_back(const T& k) {
                        data[ume] = k;
                        ++ume;
                        return data[ume - 1];
                    }
                    void pop_back() {
                        --ume;
                    }
                    bool is_manpai() {
                        if (ume >= (blocksize)) {
                            return true;
                        }
                        return false;
                    }
                    int umeta() {
                        return ume;
                    }

                    T& operator[] (int n) {
                        return data[n];
                    }
                    T operator[] (int n) const {
                        return data[n];
                    }
                private:
                    int ume;
                    T* data;
                    const int blocksize;
            };

            gon::backvector<block*> blockptrs;
            const int blocksize;
            size_t nsize = 0;
            
    };
}