#include <configs.h>
#include <sortingAlgorithms.h>
#include <generateRandomArray.h>

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

// Reads in data from the input file, returns -1 on failure, 0 on success
int readData(std::vector<int> &data, int size, std::string filepath)
{
    std::cout << "Reading in data... ";
    std::ifstream file(filepath);

    if(!file){
        std::cerr << "Error!\n";
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        file >> data[i];
    }
    
    std::cout << "Done!\n";
    return 0;
}

void verifyCorrectSort(int size, std::vector<int> &data, std::vector<int> &check)
{
    std::cout << "Double checking validity of sorted array... ";
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        if (data[i] != check[i])
        {
            std::cout << "Invalid sorting (i = " << i << ")\n";
            flag = false;
            break;
        }
    }

    if (flag)
        std::cout << "Valid sorting\n";
}

int main(int argc, char **argv){
    // Parses the command line arguments
    int size = argc > 1 ? atoi(argv[1]) : SIZE;
    int threshold = argc > 2 ? atoi(argv[2]) : HYBRID_SORT_SIZE_THRESHOLD;
    bool generate_new_array = (bool) (argc > 3 ? atoi(argv[3]) : GENERATE_NEW_ARRAY);
    int upper_bound = argc > 4 ? atoi(argv[4]) : UPPER_BOUND;

    // Generate array of random values and outputs to a text file
    if(generate_new_array){
        std::cout << "Generating new array of " << size << "... ";
        generateRandomArray(size, LOWER_BOUND, upper_bound, DESTINATION_FILE);
        std::cout << "Done!\n";
    }

    // Read in data from input file
    std::vector<int> data = std::vector<int>(size);
    if(readData(data, size, DESTINATION_FILE) == -1) return 0;

    // Performs hybrid sort
    std::cout << "Performing hybrid sort on array. Current size threshold is " 
        << threshold << std::endl;
    int total_key_comps = 0;
    
    std::clock_t start = std::clock();
    hybridSort(data, 0, size, threshold, total_key_comps);
    std::clock_t end = std::clock();

    long double elapsed_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "Total number of key comparisons: " << total_key_comps << std::endl;
    std::cout << "CPU time used: " << elapsed_time << "ms\n";

    return 0;
}