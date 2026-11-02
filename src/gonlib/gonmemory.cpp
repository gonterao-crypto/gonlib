#include "gonmemory.hpp"
#include <cstdlib>

namespace gon {
    void* calloc(size_t nmemb, size_t size) {
        return std::calloc(nmemb, size);
    }
    void free(void* ptr) {
        return std::free(ptr);
    }
    void* realloc(void* ptr, size_t new_size) {
        return std::realloc(ptr, new_size);
    }
}