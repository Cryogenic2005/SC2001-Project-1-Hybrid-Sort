#include <configs.h>
#include <utils.h>
#include <sortingAlgorithms.h>
#include <generateRandomArray.h>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <filesystem>

int main(int argc, char **argv){
    // Parses the command line arguments
    int size = argc > 1 ? atoi(argv[1]) : SIZE;
    int threshold = argc > 2 ? atoi(argv[2]) : HYBRID_SORT_SIZE_THRESHOLD;
    bool generate_new_array = (bool) (argc > 3 ? atoi(argv[3]) : GENERATE_NEW_ARRAY);
    int upper_bound = argc > 4 ? atoi(argv[4]) : UPPER_BOUND;

    if(!std::filesystem::exists(DESTINATION_FOLDER)){
        if(!std::filesystem::create_directory(DESTINATION_FOLDER)){
            throw std::runtime_error("Couldn't create directory");
        }
    }

    std::filesystem::path filepath = (DESTINATION_FOLDER / DESTINATION_FILENAME)
        .concat(std::to_string(size));

    // Generate array of random values and outputs to a text file
    if(generate_new_array){
        std::cout << "Generating new array of " << size << "... ";
        generateRandomArray(size, LOWER_BOUND, upper_bound, filepath);
        std::cout << "Done!\n";
    }

    // Read in data from input file
    std::vector<int> data = std::vector<int>(size);
    readData(data, size, filepath);

    // Performs hybrid sort
    std::cout << "Performing hybrid sort on array. Current size threshold is " 
        << threshold << std::endl;
    int total_key_comps = 0;
    
    auto start = std::chrono::steady_clock::now();
    hybridSort(data, 0, size, threshold, total_key_comps);
    auto end = std::chrono::steady_clock::now();

    long double elapsed_time = 
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0l;

    std::cout << "Total number of key comparisons: " << total_key_comps << std::endl;
    std::cout << "CPU time used: " << elapsed_time << "ms\n";

    return 0;
}