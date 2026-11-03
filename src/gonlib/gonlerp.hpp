#pragma once

namespace gon {
    template<typename T, typename Y, typename U>
    T lerp(T a, Y b, U t) {
        return a + ((b - a) * t);
    }

}