#pragma once

namespace gon {
    template<typename T>
    struct remove_ref {
        using type = T;
    };

    template<typename T>
    struct remove_ref<T&> {
        using type = T;
    };

    template<typename T>
    struct remove_ref<T&&> {
        using type = T;
    };

    template<typename T>
    constexpr typename remove_ref<T>::type&& move(T&& arg) noexcept {
        return static_cast<typename remove_ref<T>::type&&>(arg);
    }
}