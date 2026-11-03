#include "gonbmp.hpp"
#include "gonmemory.hpp"
#include <fstream>

namespace gon {
    imgfilecanvas::imgfilecanvas(int width, int height) : data(nullptr),
    linescan(0),
    r(0),
    g(0),
    b(0),
    width(width),
    height(height),
    bitcount(0) {

    }
    imgfilecanvas::~imgfilecanvas() {

    }
    int imgfilecanvas::getpointindex(int x, int y) {
        return (y * linescan) + x * (bitcount / 8);
    }
    bool imgfilecanvas::drawpoint(unsigned int x, unsigned int y) {
        if (x < 0 || x >= width) {
            return false;
        }
        if (y < 0 || y >= height) {
            return false;
        }
        unsigned int p = getpointindex(x, y);
        data[p] = b;
        data[p + 1] = g;
        data[p + 2] = r;
        return true;
    }
    char imgfilecanvas::setcolor(unsigned char r, unsigned char g, unsigned char b) {
        imgfilecanvas::r = r;
        imgfilecanvas::g = g;
        imgfilecanvas::b = b;
        return 0;
    }
    char imgfilecanvas::drawline(unsigned int nx, unsigned int ny, unsigned int x, unsigned int y) {
        y = height - y;
        int dx = (x > nx) ? x - nx : nx - x;
        int dy = (y > ny) ? y - ny : ny - y;

        int sx = (x > nx) ? 1 : -1;
        int sy = (y > ny) ? 1 : -1;

        if (dx > dy) {
            int e = -dx;
            for (int i = 0; i <= dx; i++) {
                drawpoint(nx, ny);
                if (i == dx) break;
                nx += sx;
                e += 2 * dy;
                if (e >= 0) {
                    ny += sy;
                    e -= 2 * dx;
                }
            }
        } else {

            int e = -dy;
            for (int i = 0; i <= dy; i++) {
                drawpoint(nx, ny);
                if (i == dy) break;
                ny += sy;
                e += 2 * dx;
                if (e >= 0) {
                    nx += sx;
                    e -= 2 * dy;
                }
            }
        }
        return 0;
    }
    int imgfilecanvas::getwidth() {
        return width;
    }
    int imgfilecanvas::getheight() {
        return height;
    }
    void imgfilecanvas::allpixelforloop(void (*func)(unsigned char& r, unsigned char& g, unsigned char& b)) {
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int index = getpointindex(i, j);
                func(data[index + 2], data[index + 1], data[index]);
            }
        }
    }
    void imgfilecanvas::allpixelforloop(void (*func)(unsigned char& r, unsigned char& g, unsigned char& b, int x, int y)) {
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                int index = getpointindex(i, j);
                func(data[index + 2], data[index + 1], data[index], i, j);
            }
        }
    }



    bmpfilecanvas::~bmpfilecanvas() {
        free(data);
    }
    bmpfilecanvas::bmpfilecanvas(int width, int height) : imgfilecanvas(width, height),
    head(),
    imgsize(0) {
        head.width = width;
        head.height = height;
        linescan = ((head.pixelbit * width + 31) / 32) * 4;
        bitcount = head.pixelbit;
        imgsize = linescan * head.height;
        data = (unsigned char*)calloc(imgsize, sizeof(unsigned char));
    }
    bool bmpfilecanvas::fexport() {
        head.filesize = imgsize + 54;

        std::ofstream file("main.bmp", std::ios::binary);

        if (!file) {
            return false;
        }
        file.write(reinterpret_cast<const char*>(&head), sizeof(head));
        file.write(reinterpret_cast<const char*>(data), imgsize);
        file.close();
        return true;
    }
    bool bmpfilecanvas::fexport(const char* t) {
        head.filesize = imgsize + 54;


        std::ofstream file(t, std::ios::binary);

        if (!file) {
            return false;
        }
        file.write(reinterpret_cast<const char*>(&head), sizeof(head));
        file.write(reinterpret_cast<const char*>(data), imgsize);
        file.close();
        return true;
    }
}