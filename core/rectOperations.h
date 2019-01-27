#ifndef RECTANGLEOPERATIONS_H_INCLUDED
#define RECTANGLEOPERATIONS_H_INCLUDED

#include "rectangle.h"
#include <set>
#include <iostream>
#include <math.h>
#include <stack>

class RectangleOperations
{
public:
    RectangleOperations() {}
    bool rectOverlap(Rectangle&, Rectangle&);
    int** generateIntersectionMatrix(std::vector <Rectangle>&);
    void getIntersectingRectangle(Rectangle& rectOne, Rectangle& rectTwo, Rectangle& resultingRectangle);
    void getAllCombinations(int, int, std::vector<int>&,std::vector<int>&, std::vector<std::vector<int> >&);
    void printTwoPlusWayIntersections(std::vector< std::vector<int> >& groups, std::vector<Rectangle>& rectangles);
    void printTwoWayIntersections(int** a, int dim,std::vector<Rectangle>& rectangles);

private:
    bool valueInRange(int, int, int);
};

#endif
