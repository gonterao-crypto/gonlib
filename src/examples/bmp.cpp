#include "block.hpp"
#include "../gonlib/gonbmp.hpp"

void pixelloop(unsigned char& red, unsigned char& green, unsigned char& blue, int x, int y) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
    blue += (x % 255);
    return;
}

void exa_bmp() {
    gon::bmpfilecanvas canv(100,100);
    canv.setcolor(255,255,255);
    canv.drawline(0,0,50,50);
    canv.fexport("aaa.bmp");
    return;
}