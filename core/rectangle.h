#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <vector>

class Rectangle
{
private:

    double TLX;
    double TLY;
    double width;
    double height;

    double BRX;
    double BRY;

public:
    Rectangle() {}
    Rectangle(double x, double y, double w, double h):TLX(x), TLY(y), width(w), height(h) 
    {
        BRX = x+w;
        if(y > 0){
            BRY = y - h;
        }
        else{
            if(x <= 0){
                BRY = y - h;
            }
            else{
                BRY = y + h;
            }
            
        }
    }

    //Getters
    inline double getTLX()
    {
        return TLX;
    }
    inline double getTLY()
    {
        return TLY;
    }
    inline double getBRX()
    {
        return BRX;
    }
    inline double getBRY()
    {
        return BRY;
    }
    inline double getW()
    {
        return width;
    }
    inline double getH()
    {
        return height;
    }

    //Setters
    inline void setTLX(double tlx)
    {
        TLX = tlx;
    }
    inline void setTLY(double tly)
    {
        TLY = tly;
    }
    inline void setBRX(double brx)
    {
        BRX = brx;
    }
    inline void setBRY(double bry)
    {
        BRY = bry;
    }
    inline void setW(double W)
    {
        width = W;
    }
    inline void setH(double H)
    {
        height = H;
    }
};

#endif
