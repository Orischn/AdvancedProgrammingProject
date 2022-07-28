#include <iostream>
#include <fstream>
#include <string>
#include "flower.hpp"

using namespace std;

double findMinDistance();
int getFileLength(string path);
Flower* getDataFromFile(string path);


int main(int argc, char** argv) {
    const string cFilePath = "data\\classified.csv";
    const string ucFilePath = "data\\Unclassified.csv";
    Flower* cFlowers = getDataFromFile(cFilePath);
    Flower* ucFlowers = getDataFromFile(ucFilePath);
    int cLength = getFileLength(cFilePath);
    int ucLength = getFileLength(ucFilePath);
    for (int i = 0; i < ucLength; i++) {
        ucFlowers[i].classifyFlower(cFlowers, cLength, stoi(argv[1]), Flower::euclidianDisTo);
        cout << ucFlowers[i].getFlowerType()<<endl;
    }
}

/*
 * The function gets a string path to a file and returns its length.
 * Input: A path to a file.
 * Output: The length of the file (in lines).
 */
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

/*
 * The function takes all the data from the files with information about flowers,
 * and returns a pointer to an array that contains all that data in the format of a Flower.
 * Input: a path to a file.
 * Output: a pointer to an array with the data in the file in the format of a Flower.
 */
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
        flowers[i].setFlowerType(line);
    }
    return flowers;
}