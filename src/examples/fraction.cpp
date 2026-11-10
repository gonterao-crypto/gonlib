#include "fixedvectorlength.hpp"
#include "../gonlib/gonfraction.hpp"
#include <iostream>


void exa_fraction() {
    gon::fraction a(5,2);
    std::cout << a.getdenom() << '/' << a.getnumer();
    return;
}