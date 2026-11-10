#include "fixedvectorlength.hpp"
#include "../gonlib/gonfraction.hpp"
#include <iostream>


void exa_fraction() {
    gon::fraction a(5,2);
    std::cout << a.getnumer() << '/' << a.getdenom() << '+' << std::endl;
    gon::fraction b(1,10);
    std::cout << b.getnumer() << '/' << b.getdenom() << std::endl;
    gon::fraction c(a + b);
    std::cout << '=' << c.getnumer() << '/' << c.getdenom() << std::endl;
    return;
}