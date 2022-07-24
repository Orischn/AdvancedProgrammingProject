#ifndef ADVNACEDPROGRAMMING_FLOWER_H_
#define ADVNACEDPROGRAMMING_FLOWER_H_
#include <string>

using namespace std;

class Flower {
    private :
        double sepalWidth;
        double sepalLength;
        double petalWidth;
        double petalLength;
        string flowerType;
    public :
        void setSepalWidth(double sepalWidth);
        void setSepalLength(double sepalLength);
        void setPetalWidth(double petalWidth);
        void setPetalLength(double petalLength);
        void setflowerType(string flowerType);
        string getData();
        double euclidianDisTo(Flower flower);
        double manhattanDisTo(Flower flower);
        double chebyshevDisTo(Flower flower);
};

#endif
