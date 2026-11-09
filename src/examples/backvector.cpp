#include "backvector.hpp"
#include "../gonlib/gonbackvector.hpp"
#include <iostream>


void exa_backvector() {
    gon::backvector<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    a.push_back(8);
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << std::endl;
    }
    std::cout << "size: " << a.size() << " reverse:" << a.r_size() << std::endl;
    a.push_back(8);
    std::cout << "size: " << a.size() << " reverse:" << a.r_size() << std::endl;
    std::cout << "ite: " << std::endl;
    for (auto& x : a) {
        std::cout  << x << std::endl;
    }
    return;
}