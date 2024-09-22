#include <configs.h>
#include <utils.h>
#include <sortingAlgorithms.h>
#include <generateRandomArray.h>

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

int main(int argc, char **argv){
    // Parses the command line arguments
    int size = argc > 1 ? atoi(argv[1]) : SIZE;
    bool generate_new_array = (bool) (argc > 2 ? atoi(argv[2]) : GENERATE_NEW_ARRAY);
    int upper_bound = argc > 3 ? atoi(argv[3]) : UPPER_BOUND;

    // Generate array of random values and outputs to a text file
    if(generate_new_array){
        std::cout << "Generating new array of " << size << "... ";
        generateRandomArray(size, LOWER_BOUND, upper_bound, DESTINATION_FILE);
        std::cout << "Done!\n";
    }

    // Read in data from input file
    std::vector<int> data = std::vector<int>(size);
    readData(data, size, DESTINATION_FILE);

    // Performs hybrid sort
    std::cout << "Performing merge sort on array.\n";
    int total_key_comps = 0;
    
    std::clock_t start = std::clock();
    mergeSort(data, 0, size, total_key_comps);
    std::clock_t end = std::clock();

    long double elapsed_time = 1000.0l * (end - start) / CLOCKS_PER_SEC;

    std::cout << "Total number of key comparisons: " << total_key_comps << std::endl;
    std::cout << "CPU time used: " << elapsed_time << "ms\n";

    return 0;
}