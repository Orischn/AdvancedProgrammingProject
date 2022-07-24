#include <iostream>
#include <fstream>
#include <string>
#include "flower.hpp"

using namespace std;

double findMinDistance();
int getFileLength(string path);
Flower* getDataFromFile(string path);

int main() {
    const string path = "data\\classified.csv";
    const int length = getFileLength(path);
    Flower* flowers = getDataFromFile(path);
    for (int i = 0; i < length; i++) {
        cout<<flowers[i].getData()<<endl;
    }
}

int getFileLength(string path) {
    ifstream input;
    input.open(path);
    string line;
    int count = 0;
    while(!input.eof()) {
        getline(input, line);
        count++;
    }
    input.close();
    return count;
}

Flower* getDataFromFile(string path) {
    ifstream input;
    string line;
    int length = getFileLength(path);
    Flower* flowers = new Flower[length];
    input.open(path);
    for (int i = 0; i < length; i++) {
        getline(input, line);
        flowers[i].setSepalWidth(stod(line.substr(0, line.find(','))));
        line = line.substr(line.find(',') + 1, line.length());
        flowers[i].setSepalLength(stod(line.substr(0, line.find(','))));
        line = line.substr(line.find(',') + 1, line.length());
        flowers[i].setPetalWidth(stod(line.substr(0, line.find(','))));
        line = line.substr(line.find(',') + 1, line.length());
        flowers[i].setPetalLength(stod(line.substr(0, line.find(','))));
        line = line.substr(line.find(',') + 1, line.length());
        flowers[i].setflowerType(line);
    }
    return flowers;
}