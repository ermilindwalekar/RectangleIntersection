#include "rectangle.h"
#include "rectOperations.h"
#include "utilities.h"

int main(int argc, char** argv)
{
	if(argc!=2)
	{
		std::cout<<"Please enter a JSON input\n";
		std::cout<<"solution <JSON File Name>\n";
		return 0;	
	} 

	RectangleOperations* ro = new RectangleOperations();
	vector<Rectangle> rectangles;
    
    int** iIntersectionMatrix;
    vector<int> rectangleMap;
    vector<int> vTemp;
    vector<vector<int> > allCombinations;

    //Get Data from JSON
    std::string errorMessage;
    if(!getData(rectangles, argv[1],errorMessage))
    {
        std::cout<<errorMessage<<std::endl;
        return 0;
    }

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
        ro->getAllCombinations(0, iLoop, rectangleMap, vTemp, allCombinations);
    }

    //Getting 2+ Way Intersections
    ro->printTwoPlusWayIntersections(allCombinations,rectangles);
    
    delete ro;
    return 0;
}
