// #define GONLIB_TYPO
#include "exception.hpp"
#include "../gonlib/gonexception.hpp"
#include <iostream>


void exa_exception() {
    try {
        throw gon::out_of_range("Test Out Of Range");
    } catch (gon::exception& e) {
        std::cerr << "throw~~~" << e.what() << std::endl;
    }
    return;
}