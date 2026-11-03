#include "block.hpp"
#include "../gonlib/gonconsolecolor.hpp"
#include <iostream>


void exa_consolecolor() {
    std::cout << gon::CCOLOR_RED << "red! " << std::endl;
    std::cout << gon::CCOLOR_BLUE << "blue! " << std::endl;
    std::cout << gon::CCOLOR_YELLOW << "yellow! " << std::endl;
    std::cout << gon::CCOLOR_CYAN << "e";
    std::cout << gon::CCOLOR_GREEN << "t";
    std::cout << gon::CCOLOR_MAGENDA << "c";
    std::cout << gon::CDECO_HIGH << gon::CCOLOR_BLUE << ".";
    std::cout << gon::CDECO_HIGH << gon::CCOLOR_RED << ".";
    std::cout << gon::CDECO_HIGH << gon::CCOLOR_GREEN << ".";
    std::cout << gon::CDC_DEFAULT << std::endl;
    return;
}