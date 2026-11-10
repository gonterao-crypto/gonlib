#include "fixedvectorlength.hpp"
#include "../gonlib/gonfixedvectorlength.hpp"
#include "../gonlib/gonexception.hpp"
#include <iostream>


void exa_fixedvectorlength() {
    gon::fixedvectorlength<int, 10> a;
    a.push_back(10);
    a.push_back(2);
    a.push_back(5);
    a.push_back(3);
    a.push_back(1);
    a.push_back(4);
    std::cout << "size: " << a.size() << std::endl;
    std::cout << "ite: " << std::endl;
    for (auto& x : a) {
        std::cout  << x << std::endl;
    }
    try {
        a.push_back(4);
        a.push_back(15);
        a.push_back(800);
        a.push_back(64);
        a.push_back(32); // error!
        a.push_back(16);
    } catch (gon::exception& e) {
        std::cout << "catch!" << std::endl;
        std::cout << "what: " << e.what() << std::endl;
        std::cout << "acces: " << a.errlastaccesindex() << std::endl;
        std::cout << "pop_back!" << std::endl;
        a.pop_back();
    }
    std::cout << "size: " << a.size() << std::endl;
    std::cout << "ite: " << std::endl;
    for (auto& x : a) {
        std::cout  << x << std::endl;
    }
    return;
}