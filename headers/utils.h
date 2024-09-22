#pragma once

#include <string>
#include <vector>

// Reads in data from the input file, returns -1 on failure, 0 on success
void readData(std::vector<int> &data, int size, std::string filepath);