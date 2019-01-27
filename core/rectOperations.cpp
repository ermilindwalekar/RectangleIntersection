#include "rectOperations.h"

bool RectangleOperations::valueInRange(double value, double min, double max)
{
    return ((value-max)*(value-min) <= 0); 
}
 
bool RectangleOperations::rectOverlap(Rectangle& A, Rectangle& B)
{
    bool xOverlap = valueInRange(A.getTLX(), B.getTLX(), fabs(B.getTLX() + B.getW())) ||
                    valueInRange(B.getTLX(), A.getTLX(), fabs(A.getTLX() + A.getW()));

    bool yOverlap = valueInRange(A.getTLY(), B.getTLY(), fabs(B.getTLY() + B.getH())) ||
                    valueInRange(B.getTLY(), A.getTLY(), fabs(A.getTLY() + A.getH()));

    return xOverlap && yOverlap;
}
int** RectangleOperations::generateIntersectionMatrix(std::vector<Rectangle>& rectangle)
{
    int iDimension = rectangle.size();
    // !May overrun stack thus dynamic memory allocation is must
    //int IntersectionMatrix[iDimension][iDimension];

    int** iIntersectionMatrix = new int*[iDimension];
    for(int iLoop = 0; iLoop < iDimension; ++iLoop)
        iIntersectionMatrix[iLoop] = new int[iDimension];

    for(int outerLoop = 0; outerLoop<iDimension; outerLoop++)
    {
        for(int innerLoop = 0; innerLoop<iDimension; innerLoop++)
        {
            //This will basically be a symmetrical matrix with diagonals equal to one, avoid checking 2 same polygons twice
            if(outerLoop == innerLoop)
            {
                iIntersectionMatrix[outerLoop][innerLoop] = 0;
            }
            else
            {
                iIntersectionMatrix[outerLoop][innerLoop] = rectOverlap(rectangle[outerLoop], rectangle[innerLoop]);
            }
        }
    }
    return iIntersectionMatrix;
}
void RectangleOperations::getAllCombinations(int offset, int k, std::vector<int>& rectangles,
        std::vector<int>& combination, std::vector<std::vector<int>>& myCombinations)
{

    if (k == 0)
    {
        myCombinations.push_back(combination);
        return;
    }
    for (int i = offset; i <= (int)rectangles.size() - k; ++i)
    {
        combination.push_back(rectangles[i]);
        getAllCombinations(i+1, k-1, rectangles, combination, myCombinations);
        combination.pop_back();
    }
}
void RectangleOperations::getIntersectingRectangle(Rectangle& rectOne, Rectangle& rectTwo, Rectangle& resultingRectangle)
{
    resultingRectangle.setTLX(std::max(rectOne.getTLX(), rectTwo.getTLX()));
    resultingRectangle.setTLY(std::min(rectOne.getTLY(), rectTwo.getTLY()));
    resultingRectangle.setBRX(std::min(rectOne.getBRX(), rectTwo.getBRX()));
    resultingRectangle.setBRY(std::max(rectOne.getBRY(), rectTwo.getBRY()));

    resultingRectangle.setW(fabs(resultingRectangle.getBRX()- resultingRectangle.getTLX()));
    resultingRectangle.setH(fabs(resultingRectangle.getBRY()- resultingRectangle.getTLY()));
}
void RectangleOperations::printTwoPlusWayIntersections(std::vector< std::vector<int>>& groups, std::vector<Rectangle>& rectangles)
{

    RectangleOperations* ro = new RectangleOperations();
    Rectangle intersectingRect;
    for ( auto group : groups )
    {
        std::stack<Rectangle> intersectionStack;
        for(auto rectangle: group)
        {
            if(!intersectionStack.empty())
            {
                if(ro->rectOverlap(intersectionStack.top(), rectangles[rectangle-1]))
                {
                    ro->getIntersectingRectangle(intersectionStack.top(),rectangles[rectangle-1], intersectingRect);
                    intersectionStack.pop();
                    intersectionStack.push(intersectingRect);
                }
                else
                {
                    while(! intersectionStack.empty())
                    {
                        intersectionStack.pop();
                    }
                    break;
                }
            }
            else
            {
                intersectionStack.push(rectangles[rectangle-1]);
            }
        }
        if(!intersectionStack.empty())
        {
            intersectingRect = intersectionStack.top();
            intersectionStack.pop();
            const auto& aLast = group.end()[-1];
            const auto& aSlast = group.end()[-2];
            std::cout<<"Between Rectangles ";
            for( auto rectangle : group )
            {
                if(aLast == rectangle)
                {
                    std::cout <<" and "<<rectangle;
                }
                else if(aSlast == rectangle)
                {
                    std::cout<<rectangle;
                }
                else
                {
                    std::cout<<rectangle <<", ";
                }
            }
            std::cout << " at ("<<intersectingRect.getTLX()<<","<<intersectingRect.getTLY()<<"), w = "<< intersectingRect.getW()
                 << ", h = "<< intersectingRect.getH()<< std::endl;
        }
    }
    std::cout << std::endl;
}
void RectangleOperations::printTwoWayIntersections(int** a, int dim,std::vector<Rectangle>& rectangles)
{
    std::cout<< "Intersections\n";
    RectangleOperations* ro = new RectangleOperations();
    Rectangle intersectingRect;

    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            if(a[i][j] == 1 && i<j)
            {
                ro->getIntersectingRectangle(rectangles[i], rectangles[j], intersectingRect);
                std::cout << "Between Rectangle "
                          << i+1 <<" and "<< j+1
                          << " at (" <<intersectingRect.getTLX()
                          <<","<<intersectingRect.getTLY()
                          <<"), w ="<< intersectingRect.getW()
                          <<", h = "<<intersectingRect.getH()
                          <<std::endl;
            }
        }
    }
}

