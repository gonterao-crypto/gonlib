#include "block.hpp"
#include "../gonlib/gonbmp.hpp"


void exa_bmp() {
    gon::bmpfilecanvas canv(100,100);
    canv.setcolor(255,255,255);
    canv.drawline(0,0,50,50);
    canv.fexport("aaa.bmp");
    return;
}