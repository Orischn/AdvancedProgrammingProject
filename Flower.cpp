#include <math.h>

double max(double num1, double num2) {
    if (num1 > num2) {
        return num1;
    }
    return num2;
}

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

        double euclidianDisTo(Flower flower) {
            return pow(pow(sepalLength - flower.sepalLength, 2) + pow(sepalWidth - flower.sepalWidth, 2) +
                    pow(petalLength - flower.petalLength, 2) + pow(petalWidth - flower.petalWidth, 2), 0.5);
        }

        double manhattanDisTo(Flower flower) {
            return sepalLength - flower.sepalLength + sepalWidth - flower.sepalWidth +
                    petalLength - flower.petalLength + petalWidth - flower.petalWidth;
        }

        double chebyshevDisTo(Flower flower) {
            double max1 = max(sepalLength - flower.sepalLength, sepalWidth - flower.sepalWidth);
            double max2 = max(petalLength - flower.petalLength, petalWidth - flower.petalWidth);
            return max(max1, max2);
        }
};
