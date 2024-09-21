#pragma once

#include <vector>

// Recursive step done in hybrid sort, this function covers the merging step of merge sort
void merge(std::vector<int> &data, int start, int len, int& total_key_comps); 

void hybridSort(std::vector<int> &data, int start, int len, int threshold, int& total_key_comps);

void insertionSort(std::vector<int> &data, int start, int len, int& total_key_comps);

void mergeSort(std::vector<int> &data, int start, int len, int& total_key_comps);
