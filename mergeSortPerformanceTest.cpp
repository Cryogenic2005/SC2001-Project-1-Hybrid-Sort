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
    bool generate_new_array = (bool) (argc > 2 ? atoi(argv[2]) : GENERATE_NEW_ARRAY);
    int upper_bound = argc > 3 ? atoi(argv[3]) : UPPER_BOUND;

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
    std::cout << "Performing merge sort on array.\n";
    int total_key_comps = 0;
    
    auto start = std::chrono::steady_clock::now();
    mergeSort(data, 0, size, total_key_comps);
    auto end = std::chrono::steady_clock::now();

    long double elapsed_time = 
        std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0l;

    std::cout << "Total number of key comparisons: " << total_key_comps << std::endl;
    std::cout << "CPU time used: " << elapsed_time << "ms\n";

    return 0;
}