#include <sortingAlgorithms.h>

#include<iostream>
#include <string>
#include <algorithm>
#include <vector>

void merge(std::vector<int> &data, int start, int len, int& total_key_comps){
    std::vector<int> temp = std::vector<int>(len);

    int head1 = start;
    int head2 = start + (len / 2);

    // Copies the smaller value to an auxiliary array in each of the half through 2 iterators
    for(int i = 0; i < len; i++){
        if(head1 >= start + (len / 2)){
            while(head2 < start + len) temp[i++] = data[head2++];
            break;
        }

        if(head2 >= start + len){
            while(head1 < start + (len / 2)) temp[i++] = data[head1++];
            break;
        }

        total_key_comps++;
        temp[i] = data[head1] <= data[head2] ? data[head1++] : data[head2++];
    }

    // Copy back the sorted values
    for(int i = 0; i < len; i++){
        data[i+start] = temp[i];
    }
}

void hybridSort(std::vector<int> &data, int start, int len, int threshold, int& total_key_comps){
    if (len <= threshold){
        insertionSort(data, start, len, total_key_comps);
    }
    else{ // Perform merge sort
        // Divide and conquer step
        hybridSort(data, start, len / 2, threshold, total_key_comps); // first half len rounded down
        hybridSort(data, start + (len / 2), (len + 1) / 2, threshold, total_key_comps); // second half len rounded up

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