#pragma once

#include <string>
#include <filesystem>

/* Configs for random array generation */ 

// Array size. Can be modified through the first argument when calling the program through the terminal.
const int SIZE = 1e7;
// Minimum value that can appear in the array
const int LOWER_BOUND = 1; 
// Maximum value that can appear in the array
const int UPPER_BOUND = 1e9; 
const std::filesystem::path DESTINATION_FOLDER = "data";
const std::filesystem::path DESTINATION_FILENAME = "data";

/* Configs for hybrid sort algorithm */

// For arrays smaller or equal size than this threshold,
// the algorithm will use insertion sort, otherwise it will
// use merge sort. Can be modified through the second argument
// when calling the program through the terminal.
const int HYBRID_SORT_SIZE_THRESHOLD = 4;

/* General purpose configs */

// Can be modified through the third argument when calling the program through the terminal
const bool GENERATE_NEW_ARRAY = true;