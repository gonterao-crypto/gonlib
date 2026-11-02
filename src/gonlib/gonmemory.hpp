#pragma once

namespace gon {
    using size_t = unsigned long long;
    void* calloc(size_t nmemb, size_t size);
    void free(void* ptr);
    void* realloc(void* ptr, size_t new_size);
}