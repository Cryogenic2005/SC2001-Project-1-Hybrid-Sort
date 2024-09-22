#include <sortingAlgorithms.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void merge(std::vector<int> &data, int start, int len, int& total_key_comps){
    // Assumes that the given subarray from the parameters have the following structure:
    // - The subarray can be divided into 2 halves of length len / 2 and (len + 1) / 2
    // - Each half is sorted in increasing order
    // The function will sort this subarray inplace by merging the two halves.

    // Auxiliary array to hold intermediate results during merging process
    static std::vector<int> temp; // Static variable to avoid reallocating large sized vectors every call
    if(temp.size() < (long long unsigned) len) temp.resize(len); // Resizing static vector whenever necessary

    // Variables to store head and end indices 
    int head_temp = 0;
    int head1 = start;
    int end1 = start + (len / 2);
    int head2 = start + (len / 2);
    int end2 = start + len;

    // Copies the smaller value in each of the half through 2 iterators to the auxiliary array
    while(head1 < end1 && head2 < end2){
        total_key_comps++; // Counts the number of key comparisons
        temp[head_temp++] = data[head1] <= data[head2] ? data[head1++] : data[head2++];
    }

    // Copies remaining values to temp array
    while(head1 < end1){
        temp[head_temp++] = data[head1++];
    }

    // Minor optimization:
    // No need to do the same for head2, since the 'missing' remaining greatest values
    // in the temp array is already sorted in the correct position in the original array
    // while(head2 < end2){
    //     temp[head_temp++] = data[head2++];
    // }

    // Copy back the sorted values to orginal subarray
    std::copy(temp.begin(), temp.begin() + head_temp, data.begin() + start);
}

void hybridSort(std::vector<int> &data, int start, int len, int threshold, int& total_key_comps){
    if (len <= threshold){
        insertionSort(data, start, len, total_key_comps);
    }
    else{ // Perform merge sort
        // Divide and conquer step
        hybridSort(data, start, len / 2, threshold, total_key_comps);
        hybridSort(data, start + (len / 2), (len + 1) / 2, threshold, total_key_comps);

        // Merges the two lists
        merge(data, start, len, total_key_comps);
    }
}

void insertionSort(std::vector<int> &data, int start, int len, int& total_key_comps){
    for (int i = 0; i < len; i++){
        for(int j = start + i; j > start; j--){
            total_key_comps++;
            if(data[j] < data[j-1]){
                std::swap(data[j], data[j-1]);
            }
            else break;
        }
    }
}

void mergeSort(std::vector<int> &data, int start, int len, int& total_key_comps){
    if(len == 1) return; // Default case, array of length 1 is already sorted.
    
    // Divide and conquer step
    mergeSort(data, start, len / 2, total_key_comps); // first half len rounded down
    mergeSort(data, start + (len / 2), (len + 1) / 2, total_key_comps); // second half len rounded up

    // Merges the two lists
    merge(data, start, len, total_key_comps);
}