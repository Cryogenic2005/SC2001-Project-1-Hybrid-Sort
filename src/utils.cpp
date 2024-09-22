#include <utils.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void readData(std::vector<int> &data, int size, std::string filepath)
{
    std::cout << "Reading in data... ";
    std::ifstream file(filepath + ".dat");

    if(!file){
        throw new std::runtime_error("Couldn't open file for reading.");
    }

    file.read(reinterpret_cast<char*>(data.data()), size * sizeof(int));

    std::cout << "Done!\n";
}