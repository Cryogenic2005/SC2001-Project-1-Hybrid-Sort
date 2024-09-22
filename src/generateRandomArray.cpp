#include <generateRandomArray.h>

#include <iostream>
#include <fstream>
#include <string>
#include <random>

void generateRandomArray(int size, int lower_bound, int upper_bound, std::string filepath){
    std::ofstream file(filepath);

    if(!file){
        std::cerr << "Couldn't open file " << filepath << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(lower_bound, upper_bound);

    for (int i = 0; i < size; i++){
        file << dist(gen) << " ";
    }
}