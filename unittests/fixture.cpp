#include "fixture.h"

char* FILENAME;

TEST_F(FunctionalFixture, validLoadData)
{
    //Get Data from json
    EXPECT_TRUE(getData(rectangles, FILENAME, errorMessage));
}

TEST_F(FunctionalFixture, DISABLED_invalidLoadData)
{
    //Get Data from json
    EXPECT_FALSE(getData(rectangles, FILENAME, errorMessage));
    std::cout<<errorMessage<<std::endl;
}

TEST_F(FunctionalFixture, DISABLED_invalidJson)
{
    //Get Data from json
    getData(rectangles, FILENAME, errorMessage);
    EXPECT_GT(errorMessage.length(), 0);
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

TEST_F(FunctionalFixture, overlapFasleCheck)
{
    Rectangle rectOne(100,100,250,80);
    Rectangle rectTwo(120,200,250,150);

    EXPECT_FALSE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapQuad1Check)
{
    Rectangle rectOne(2,2,1,5);
    Rectangle rectTwo(1,-1,3,3);

    EXPECT_TRUE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapQuad2Check)
{
    Rectangle rectOne(-1,1,1,1);
    Rectangle rectTwo(-2,2,2,2);

    EXPECT_TRUE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapQuad3Check)
{
    Rectangle rectOne(-1,-1,1,1);
    Rectangle rectTwo(-2,-2,2,2);

    EXPECT_TRUE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapQuad4Check)
{
    Rectangle rectOne(2,-2,2,2);
    Rectangle rectTwo(1,-1,2,2);

    EXPECT_TRUE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapFalseQuad1Check)
{
    Rectangle rectOne(1,1,1,1);
    Rectangle rectTwo(10,10,1,1);

    EXPECT_FALSE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapFalseQuad2Check)
{
    Rectangle rectOne(-10,10,1,1);
    Rectangle rectTwo(-1,1,1,1);

    EXPECT_FALSE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapFalseQuad3Check)
{
    Rectangle rectOne(-1,-1,1,1);
    Rectangle rectTwo(-10,-10,1,1);

    EXPECT_FALSE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, overlapFalseQuad4Check)
{
    Rectangle rectOne(1,-1,1,1);
    Rectangle rectTwo(10,-10,1,11);

    EXPECT_FALSE(ro->rectOverlap(rectOne, rectTwo));
}

TEST_F(FunctionalFixture, trueIntersectionCheck)
{
    Rectangle rectOne(-1,-1,1,1);
    Rectangle rectTwo(-0.5,-0.5,1,1);
    Rectangle intersectingRect;

    ro->getIntersectingRectangle(rectOne, rectTwo, intersectingRect);
}

TEST_F(FunctionalFixture, DISABLED_getSolution)
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
