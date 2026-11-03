#include "block.hpp"
#include "../gonlib/gonbmp.hpp"
#include <iostream>

void pixelloop(unsigned char& red, unsigned char& green, unsigned char& blue, int x, int y) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
    blue += (x % 255);
void pixelloop(unsigned char& red, unsigned char& green, unsigned char& blue) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
    return;
}

void exa_bmp() {
    gon::bmpfilecanvas canv(100,100);
    if (!canv.fimport("aaa.bmp")) {
        canv.setcolor(255,255,255);
        canv.drawline(0,0,100,100);
    } else {
        canv.allpixelforloop(pixelloop);
    }

    canv.fexport("aaa.bmp");
    return;
}