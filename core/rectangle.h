#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <vector>
#include <iostream>
class Rectangle
{
private:

    int TLX;
    int TLY;
    int width;
    int height;

    
    int BRX;
    int BRY;

public:
    Rectangle() {}
    Rectangle(int x, int y, int w, int h):TLX(x), TLY(y), width(w), height(h) 
    {
        BRX = x + w;
        BRY = y + h;
    }

    //Getters
    inline int getTLX()
    {
        return TLX;
    }
    inline int getTLY()
    {
        return TLY;
    }
    inline int getBRX()
    {
        return BRX;
    }
    inline int getBRY()
    {
        return BRY;
    }
    inline int getW()
    {
        return width;
    }
    inline int getH()
    {
        return height;
    }

    //Setters
    inline void setTLX(int tlx)
    {
        TLX = tlx;
    }
    inline void setTLY(int tly)
    {
        TLY = tly;
    }
    inline void setBRX(int brx)
    {
        BRX = brx;
    }
    inline void setBRY(int bry)
    {
        BRY = bry;
    }
    inline void setW(int W)
    {
        width = W;
    }
    inline void setH(int H)
    {
        height = H;
    }
};

#endif
