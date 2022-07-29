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
    cout<<"k="<<argv[1]<<endl<<endl;
    cout<<"euclidian:"<<endl<<endl;
    for (int i = 0; i < ucLength; i++) {
        ucFlowers[i].classifyFlower(cFlowers, cLength, stoi(argv[1]), &Flower::euclidianDisTo);
        cout<<ucFlowers[i].getFlowerType()<<endl;
    }
    cout<<endl<<"manhattan:"<<endl<<endl;
    for (int i = 0; i < ucLength; i++) {
        ucFlowers[i].classifyFlower(cFlowers, cLength, stoi(argv[1]), &Flower::manhattanDisTo);
        cout<<ucFlowers[i].getFlowerType()<<endl;
    }
    cout<<endl<<"chebyshev:"<<endl<<endl;
    for (int i = 0; i < ucLength; i++) {
        ucFlowers[i].classifyFlower(cFlowers, cLength, stoi(argv[1]), &Flower::chebyshevDisTo);
        cout<<ucFlowers[i].getFlowerType()<<endl;
    }
    cout<<endl<<endl;
}