#include <generateRandomArray.h>

#include <iostream>
#include <fstream>
#include <string>
#include <random>

void generateRandomArray(int size, int lower_bound, int upper_bound, std::string filepath){
    std::ofstream file(filepath + ".txt");
    std::ofstream binfile(filepath + ".dat", std::ios::binary);

    if(!file || !binfile){
        throw new std::runtime_error("Couldn't open file for writing.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(lower_bound, upper_bound);

    std::vector<int> generated_values = std::vector<int>(size); 

    for (int i = 0; i < size; i++){
        generated_values[i] = dist(gen);
        file << generated_values[i] << " ";
    }

    binfile.write(reinterpret_cast<const char*>(generated_values.data()), size * sizeof(int));
}