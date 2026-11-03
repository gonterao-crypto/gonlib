#include "block.hpp"
#include "../gonlib/gonblock.hpp"
#include <iostream>


void exa_block() {
    gon::blocks<float> b(10);
    b.push_back(2.0f);
    b.push_back(20.0f);
    b.push_back(5.0f);
    b.push_back(2.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.push_back(20.0f);
    b.pop_back();
    b.pop_back();
    b.pop_back();
    b.pop_back();
    b.pop_back();
    b.pop_back();
    b.pop_back();
    b.pop_back();
    b.push_back(20.0f);
    for (int i = 0; i < b.size(); ++i) {
        std::cout << b[i] << std::endl;
    }
    std::cout << "size: " << b.size() << std::endl;
    return;
}