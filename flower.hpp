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
        /*
         * Returns the euclidian distance from this flower to a different flower.
         * Input: A flower.
         * Output: The euclidian distance from this flower to the given flower.
         */
        double euclidianDisTo(Flower flower);
        /*
         * Returns the manhattan distance from this flower to a different flower.
         * Input: A flower.
         * Output: The manhattan distance from this flower to the given flower.
         */
        double manhattanDisTo(Flower flower);
        /*
         * Returns the chebyshev distance from this flower to a different flower.
         * Input: A flower.
         * Output: The chebyshev distance from this flower to the given flower.
         */
        double chebyshevDisTo(Flower flower);

        void classifyFlower(Flower* cFlowers, int amt,
        int k, double (*compare)(Flower));
};

#endif
