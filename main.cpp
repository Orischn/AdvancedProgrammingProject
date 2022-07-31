#include <iostream>
#include "file.hpp"
#include "flower.hpp"

using namespace std;

int main(int argc, char** argv) {
    const string cFilePath = "data/classified.csv";
    const string ucFilePath = "data/Unclassified.csv";
    Flower* cFlowers = getDataFromFile(cFilePath);
    Flower* ucFlowers = getDataFromFile(ucFilePath);
    int cLength = getFileLength(cFilePath);
    int ucLength = getFileLength(ucFilePath);
    for (int i = 0; i < ucLength; i++) {
        ucFlowers[i].classifyFlower(cFlowers, cLength, stoi(argv[1]), &Flower::euclidianDisTo);
    }
    writeDataToFile(ucFlowers, ucLength, "out/euclidean_output.csv");
    for (int i = 0; i < ucLength; i++) {
        ucFlowers[i].classifyFlower(cFlowers, cLength, stoi(argv[1]), &Flower::manhattanDisTo);
    }
    writeDataToFile(ucFlowers, ucLength, "out/manhattan_output.csv");
    for (int i = 0; i < ucLength; i++) {
        ucFlowers[i].classifyFlower(cFlowers, cLength, stoi(argv[1]), &Flower::chebyshevDisTo);
    }
    writeDataToFile(ucFlowers, ucLength, "out/chebyshev_output.csv");
    delete[] cFlowers;
    delete[] ucFlowers;
}