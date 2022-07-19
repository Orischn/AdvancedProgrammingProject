#include <math.h>

class Flower {
    private :
        double sepalWidth;
        double sepalLength;
        double petalWidth;
        double petalLength;
    public :
        Flower(double sw, double sl, double pw, double pl) {
            sepalWidth = sw;
            sepalLength = sl;
            petalWidth = pw;
            petalLength = pl;
        }

        double compare(Flower flower) {
            return pow(pow(sepalLength - flower.sepalLength, 4) + pow(sepalWidth - flower.sepalWidth, 4) +
                    pow(petalLength - flower.petalLength, 4) + pow(petalWidth - flower.petalWidth, 4), 0.25);
        }
};