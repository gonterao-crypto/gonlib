#pragma once

namespace gon {
    class imgfilecanvas {
        public:
            imgfilecanvas(int width, int height);
            virtual ~imgfilecanvas() = 0;
            virtual bool fexport() = 0;
            int getpointindex(int x, int y);
            bool drawpoint(unsigned int x, unsigned int y);
            char setcolor(unsigned char r, unsigned char g, unsigned char b);
            char drawline(unsigned int nx, unsigned int ny, unsigned int x, unsigned int y);
        protected:
            int linescan;
            int width, height;
            int bitcount;
            unsigned char* data;
            unsigned char r;
            unsigned char g;
            unsigned char b;
    };
    
    #pragma pack(push, 1)
    struct bmpheader {
        // filehead
        unsigned short filetype = 0x4d42;
        unsigned int filesize = 0;
        unsigned short y1 = 0;
        unsigned short y2 = 0;
        unsigned int imgdataoffset = 54;
        // info type head
        unsigned int headsize = 40;
        unsigned int width = 0;
        unsigned int height = 0;
        unsigned short plane = 1;
        unsigned short pixelbit = 24;
        unsigned int comptype = 0;
        unsigned int imgdatasize = 0;
        unsigned int xdpi = 300;
        unsigned int ydpi = 300;
        unsigned int colorindex = 0;
        unsigned int Jindex = 0;
    };
    #pragma pack(pop)

    class bmpfilecanvas : public imgfilecanvas {
        public:
            bmpfilecanvas(int width, int height);
            ~bmpfilecanvas() override;
            bool fexport() override final;
        private:
            bmpheader head;
            int imgsize;
    };
}