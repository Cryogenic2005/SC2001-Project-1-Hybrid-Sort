#include <utils.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

void readData(std::vector<int> &data, int size, std::filesystem::path filepath)
{
    std::cout << "Reading in data... ";
    std::ifstream file(filepath.replace_extension(".dat"));

    if(!file){
        throw new std::runtime_error("Couldn't open file for reading.");
    }

    file.read(reinterpret_cast<char*>(data.data()), size * sizeof(int));

    std::cout << "Done!\n";
}