#include "json/json.h"
#include <fstream>
#include <rectOperations.h>

using namespace std;

bool getData(std::vector<Rectangle>& rectangles, string fileName, string& errorMessage)
{
    ifstream ifs(fileName);
    if(!ifs){
            cout<<"File "<< fileName<< " not found\n";
            return false;
    }

    string text( (istreambuf_iterator<char>(ifs) ),
                 (istreambuf_iterator<char>()    ) );
    Json::CharReaderBuilder builder;

    Json::CharReader * reader = builder.newCharReader();

    Json::Value root;
    string errors;

    bool parsingSuccessful = reader->parse(text.c_str(), text.c_str() + text.size(), &root, &errors);
    delete reader;

    if ( !parsingSuccessful )
    {
        errorMessage = errors;
        return parsingSuccessful;
    }

    for( Json::Value::const_iterator outer = root.begin() ; outer != root.end() ; outer++ )
    {
        for( Json::Value::const_iterator inner = (*outer).begin() ; inner!= (*outer).end() ; inner++ )
        {
            rectangles.push_back(
                Rectangle((*inner)["x"].asInt(),
                          (*inner)["y"].asInt(),
                          (*inner)["w"].asInt(),
                          (*inner)["h"].asInt()
                         ));
        }
    }
    return parsingSuccessful;
}

void printInputRectangles(vector<Rectangle> & rectangles)
{
    cout<<"Input:"<<endl;
    for(int iLoop = 0; iLoop < (int)rectangles.size(); iLoop++)
    {
        cout<<iLoop+1<<": Rectangle at ("<<rectangles[iLoop].getTLX()<<","
            <<rectangles[iLoop].getTLY()<<"),("<<rectangles[iLoop].getBRX()<<","
            <<rectangles[iLoop].getBRY()<<"),w = "<<rectangles[iLoop].getW()<<", h = "<<rectangles[iLoop].getH()<<endl;
    }
    cout<<endl;
}
