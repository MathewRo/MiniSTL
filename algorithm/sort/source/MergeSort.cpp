#include "MergeSort.hpp"
#include <algorithm>


/**
 * This a private helper function which does the merge and sort
 * TC - O(N1) + O(N2) + O(N1 + N2) ~= O(n) 
 * WC complexity is O(n) when high - low = n
 * @param arr
 * @param low
 * @param high
 */
static void Merge(std::vector <size_t> & arr, const size_t &low, const size_t &mid, const size_t &high) {
    size_t N1 = mid + 1 - low;
    size_t N2 = high - mid;
    // We need to copy the data to temp left and right arrays before merging.
    // Merge is not an in place algorithm
    size_t L[N1], R[N2];
    // O(N1)
    for (size_t i = 0; i < N1; i++) {
        L[i] = arr[i + low]; 
    }
    
    // O(N2)
    for (size_t i = 0; i < N2; i++) {
        R[i] = arr[i + mid + 1];
    }
    size_t i = 0;
    size_t j = 0;
    // This should start from low
    size_t k = low;
    // Merge O(N1 + N2)
    while ( i < N1 && j < N2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < N1) {
        arr[k] = L[i];
        k++;
        i++;
    }
    
    while (j < N2) {
        arr[k] = R[j];
        k++;
        j++; 
    }
}

/**
 * Recursevely breaks the given array until it can no longer be divided
 * Recurrence Reln T(n) = 2T(n/2) + Theta(n)
 * Total Complexity = Theta(nLogn)
 * https://www.geeksforgeeks.org/merge-sort/
 * @param arr
 * @param low
 * @param high
 */
void MergeSort(std::vector <size_t> & arr, const size_t & low, const size_t & high) {
    if (high > low) {
        size_t mid = (low + high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        // this is called approx log(n) times
        Merge(arr, low, mid, high);
    }
}

/**
 * Iterative approach to merge sort
 * @param arr
 * @param low
 * @param high
 */
void MergeSortIterative(std::vector <size_t> & arr, const size_t & low, const size_t & high) {
    
    for (size_t i = 1; i <= (high - low); i *= 2) {
        for (size_t left_end = 0; left_end < (high - low); left_end += 2*i) {
            size_t mid = std::min(left_end + i - 1, high - low);
            size_t right_end = std::min (left_end + 2*i - 1, high - low);
            // this is called approx log(n) times
            Merge(arr, left_end, mid, right_end);
        }
    }
}