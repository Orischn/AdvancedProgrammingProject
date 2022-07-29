#include "flower.hpp"
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

Flower::Flower() {
    this->sepalWidth = 0;
    this->sepalLength = 0;
    this->petalWidth = 0;
    this->petalLength = 0;
}

Flower::Flower(const Flower& flower) {
    this->sepalWidth = flower.sepalWidth;
    this->sepalLength = flower.sepalLength;
    this->petalWidth = flower.petalWidth;
    this->petalLength = flower.petalLength;
    this->flowerType = flower.flowerType;
}

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

void Flower::setFlowerType(string flowerType) {
    this->flowerType = flowerType;
}

string Flower::getFlowerType() {
    return this->flowerType;
}

double Flower::euclidianDisTo(Flower flower) {
    return pow(pow(abs(this->sepalLength - flower.sepalLength), 2) +
            pow(abs(this->sepalWidth - flower.sepalWidth), 2) +
            pow(abs(this->petalLength - flower.petalLength), 2) +
            pow(abs(this->petalWidth - flower.petalWidth), 2), 0.5);
}

double Flower::manhattanDisTo(Flower flower) {
    return abs(this->sepalLength - flower.sepalLength) +
            abs(this->sepalWidth - flower.sepalWidth) +
            abs(this->petalLength - flower.petalLength) +
            abs(this->petalWidth - flower.petalWidth);
}

double Flower::chebyshevDisTo(Flower flower) {
    double max1 = max(abs(this->sepalLength - flower.sepalLength),
                        abs(this->sepalWidth - flower.sepalWidth));
    double max2 = max(abs(this->petalLength - flower.petalLength),
                        abs(this->petalWidth - flower.petalWidth));
    return max(max1, max2);
}

void Flower::classifyFlower(Flower* cFlowers, int amt, int k, double (Flower::*distance)(Flower)) {
    for (int i = 0; i < amt; i++) {
        for (int j = i + 1; j < amt; j++) {
            if ((this->*distance)(cFlowers[i]) > (this->*distance)(cFlowers[j])) {
                Flower temp = cFlowers[i];
                cFlowers[i] = cFlowers[j];
                cFlowers[j] = temp;
            }
        }
    }
    int flowerTypes[3];
    for (int i = 0; i < 3; i++) {
        flowerTypes[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        if(cFlowers[i].flowerType.compare("Iris-setosa") == 0) {
            flowerTypes[0]++;
        } else if (cFlowers[i].flowerType.compare("Iris-versicolor") == 0) {
            flowerTypes[1]++;
        } else {
            flowerTypes[2]++;
        }
    }
    int maxI = 0, maxN = 0;
    for (int i = 0; i < 3; i++) {
        if (flowerTypes[i] > maxN) {
            maxN = flowerTypes[i];
            maxI = i;
        }
    }
    if (maxI == 0) {
        this->flowerType = "Iris-setosa";
    } else if (maxI == 1) {
        this->flowerType = "Iris-versicolor";
    } else {
        this->flowerType = "Iris-virginica";
    }
}
