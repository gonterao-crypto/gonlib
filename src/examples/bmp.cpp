#include "block.hpp"
#include "../gonlib/gonbmp.hpp"
#include <iostream>

void pixelloop(gon::imgfilecanvas& canv, unsigned char& red, unsigned char& green, unsigned char& blue, int x, int y) {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
    blue += (x % 255);
    unsigned char tempr = 0;
    unsigned char tempg = 0;
    unsigned char tempb = 0;
    canv.getpixel(x - 1, y, tempr, tempg, tempb);
    green += tempg;
    
    return;
}

void exa_bmp() {
    gon::bmpfilecanvas canv(100,100);
    if (!canv.fimport("aaa.bmp")) {
        canv.setcolor(255,255,255);
        canv.drawline(0,0,100,100);
    } else {
        canv.rectinpixelforloop(0, 0, 50, 50, pixelloop);
    }

    canv.fexport("aaa.bmp");
    return;
}