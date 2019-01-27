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
