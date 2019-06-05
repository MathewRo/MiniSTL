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
void SelectionSort(std::vector<size_t>& arr) {
    size_t N = arr.size();
    size_t min;
    for (size_t i = 0; i < N-1; i++) {
        min = i;
        for (size_t j = i+1; j < N; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[min], arr[i]);
    }
}