#include "gtest/gtest.h"
#include "rectangle.h"
#include "rectOperations.h"
#include "utilities.h"

using namespace std;
class FunctionalFixture : public ::testing::Test
{
protected:
    FunctionalFixture() {}

    int nCr(int iN, int iR)
    {
        return factorial(iN) / (factorial(iR) * factorial(iN - iR));
    }

    // Returns factorial of input
    int factorial(int input)
    {
        int iResult = 1;
        for (int iLoop = 2; iLoop <= input; iLoop++)
            iResult = iResult * iLoop;
        return iResult;
    }

    virtual void SetUp()
    {
        ro = new RectangleOperations();
    }

    virtual void TearDown()
    {
        delete ro;
    }

    RectangleOperations* ro;
    vector<Rectangle> rectangles;
    int** iIntersectionMatrix;
    vector<int> rectangleMap;
    vector<int> combinations;
    vector<vector<int> > allCombinations;
    std::string errorMessage;
};
