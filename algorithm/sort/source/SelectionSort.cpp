#include "SelectionSort.hpp"
#include <algorithm>

/**
 * Sort an array using the Selection Sort
 * algorithm. Time complexity is 
 * (N-1) + (N-2) + ... 1 = (N-1)(N-2)/2 = O(N^2)
 * @param arr
 * 
 */
void SelectionSort(std::vector<size_t>& arr) {
    int64_t N = arr.size();
    int64_t min;
    for (int64_t i = 0; i < N-1; i++) {
        min = i;
        for (int64_t j = i+1; j < N; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[min], arr[i]);
    }
}