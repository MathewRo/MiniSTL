#include "SelectionSort.hpp"
#include <algorithm>

/**
 * Sort an array using the Selection Sort
 * algorithm. Time complexity is 
 * (N-1) + (N-2) + ... 1 = (N-1)(N-2)/2 = O(N^2)
 * @param arr
 * 
 *https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/tutorial/
 */
void SelectionSort(std::vector<uint64_t>& arr) {
    uint64_t N = arr.size();
    uint64_t min;
    for (uint64_t i = 0; i < N-1; i++) {
        min = i;
        for (uint64_t j = i+1; j < N; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[min], arr[i]);
    }
}