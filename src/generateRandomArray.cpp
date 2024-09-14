#include <generateRandomArray.h>

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

void generateRandomArray(int size, int lower_bound, int upper_bound, std::string filepath){
    std::ofstream file(filepath);

    if(!file){
        std::cerr << "Couldn't open file " << filepath << std::endl;
        return;
    }

    const int SAMPLE_SIZE_LENGTH = upper_bound - lower_bound + 1;

    std::srand(std::time(nullptr));
    for (int i = 0; i < size; i++){
        file << std::rand() % SAMPLE_SIZE_LENGTH + lower_bound << " ";
    }
}