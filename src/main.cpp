#include <iostream>
#include "gonlib/gonblock.hpp"

int main() {
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
    std::cout << "ahahahah" << std::endl;


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
    for (int i = 0; i < b.size(); ++i) {
        std::cout << b[i] << std::endl;
    }
    std::cout << "size: " << b.size() << std::endl;
    return 0;
}