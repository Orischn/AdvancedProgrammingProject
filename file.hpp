#ifndef ADVNACEDPROGRAMMING_FILE_H_
#define ADVNACEDPROGRAMMING_FILE_H_

#include <string>
#include "flower.hpp"

int getFileLength(string path);
Flower* getDataFromFile(string path);
void writeDataToFile(Flower* flowers, int amt, string path);

#endif