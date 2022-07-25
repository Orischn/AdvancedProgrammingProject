#include "flower.hpp"
#include <math.h>
#include <string>

using namespace std;

void Flower::setSepalWidth(double sepalWidth) {
    this->sepalWidth = sepalWidth;
}

void Flower::setSepalLength(double sepalLength) {
    this->sepalLength = sepalLength;
}

void Flower::setPetalWidth(double petalWidth) {
    this->petalWidth = petalWidth;
}

void Flower::setPetalLength(double petalLength) {
    this->petalLength = petalLength;
}

void Flower::setflowerType(string flowerType) {
    this->flowerType = flowerType;
}

double Flower::euclidianDisTo(Flower flower) {
    return pow(pow(sepalLength - flower.sepalLength, 2) + pow(sepalWidth - flower.sepalWidth, 2) +
            pow(petalLength - flower.petalLength, 2) + pow(petalWidth - flower.petalWidth, 2), 0.5);
}

double Flower::manhattanDisTo(Flower flower) {
    return sepalLength - flower.sepalLength + sepalWidth - flower.sepalWidth +
            petalLength - flower.petalLength + petalWidth - flower.petalWidth;
}

double Flower::chebyshevDisTo(Flower flower) {
    double max1 = max(sepalLength - flower.sepalLength, sepalWidth - flower.sepalWidth);
    double max2 = max(petalLength - flower.petalLength, petalWidth - flower.petalWidth);
    return max(max1, max2);
}
