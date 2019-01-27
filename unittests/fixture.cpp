#include "fixture.h"

char* FILENAME;

TEST_F(FunctionalFixture, validLoadData)
{
    //Get Data from rectangle
    EXPECT_TRUE(getData(rectangles, FILENAME, errorMessage));
}

TEST_F(FunctionalFixture, DISABLED_invalidLoadData)
{
    //Get Data from rectangle
    EXPECT_FALSE(getData(rectangles, FILENAME, errorMessage));
    std::cout<<errorMessage<<std::endl;
}

TEST_F(FunctionalFixture, DISABLED_combinationsCheck)
{
    //Get Data from rectangle
    ASSERT_TRUE(getData(rectangles, FILENAME, errorMessage));

    //Making rectangle mapping
    for(int iLoop = 0; iLoop < (int)rectangles.size(); iLoop++)
    {
        rectangleMap.push_back(iLoop+1);
    }

    for(int iLoop = 3; iLoop<= (int)rectangles.size(); iLoop++)
    {
        ro->getAllCombinations(0, iLoop, rectangleMap, combinations, allCombinations);
        EXPECT_EQ((int)allCombinations[iLoop].size(),nCr((int)rectangles.size(), iLoop));
    }
}

TEST_F(FunctionalFixture, overlapCheck)
{
    Rectangle rectOne(2,3,5,4);
    Rectangle rectTwo(3,4,6,10);

    EXPECT_TRUE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapQuad3Check)
{
    Rectangle rectOne(-1,0,1,1);
    Rectangle rectTwo(0,0,2,2);

    EXPECT_TRUE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapFalseCheck)
{
    Rectangle rectOne(-1,-1,1,1);
    Rectangle rectTwo(10,12,6,10);

    EXPECT_FALSE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, intersectionCheck)
{
    Rectangle rectOne(-1,-1,1,1);
    Rectangle rectTwo(-0.5,-0.5,1,1);
    Rectangle intersectingRect;

    ro->getIntersectingRectangle(rectOne, rectTwo, intersectingRect);
    std::cout << " at ("<<intersectingRect.getTLX()<<","<<intersectingRect.getTLY()<<"), w = "<< intersectingRect.getW()
                 << ", h = "<< intersectingRect.getH()<< std::endl;
}

TEST_F(FunctionalFixture, getSolution)
{
    //Get Data from rectangle
    ASSERT_TRUE(getData(rectangles, FILENAME, errorMessage));

    //Making rectangle mapping
    for(int iLoop = 0; iLoop < (int)rectangles.size(); iLoop++)
    {
        rectangleMap.push_back(iLoop+1);
    }

    printInputRectangles(rectangles);

    //Getting 2 Way Intersections
    iIntersectionMatrix = ro->generateIntersectionMatrix(rectangles);
    ro->printTwoWayIntersections(iIntersectionMatrix, rectangles.size(), rectangles);

    //Getting combinations
    for(int iLoop = 3; iLoop<= (int)rectangles.size(); iLoop++)
    {
        ro->getAllCombinations(0, iLoop, rectangleMap, combinations, allCombinations);
    }

    //Getting 2+ Way Intersections
    ro->printTwoPlusWayIntersections(allCombinations,rectangles);
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    if(argc < 2)
    {
        std::cout<<"Please pass the json input file\n";
        return 0;
    }
    //This is Dirty !
    FILENAME = argv[1];
    return RUN_ALL_TESTS();
}
