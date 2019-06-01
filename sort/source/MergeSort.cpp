#include "MergeSort.hpp"


/**
 * This a private helper function which does the merge and sort
 * TC - O(N1) + O(N2) + O(N1 + N2) ~= O(n) 
 * WC complexity is O(n) when high - low = n
 * @param arr
 * @param low
 * @param high
 */
static void Merge(std::vector <uint64_t> & arr, const uint64_t &low, const uint64_t &mid, const uint64_t &high) {
    uint64_t N1 = mid + 1 - low;
    uint64_t N2 = high - mid;
    // We need to copy the data to temp left and right arrays before merging.
    // Merge is not an in place algorithm
    uint64_t L[N1], R[N2];
    // O(N1)
    for (uint64_t i = 0; i < N1; i++) {
        L[i] = arr[i + low]; 
    }
    
    // O(N2)
    for (uint64_t i = 0; i < N2; i++) {
        R[i] = arr[i + mid + 1];
    }
    uint64_t i = 0;
    uint64_t j = 0;
    // This should start from low
    uint64_t k = low;
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
void MergeSort(std::vector <uint64_t> & arr, const uint64_t & low, const uint64_t & high) {
    if (high > low) {
        uint64_t mid = (low + high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        // this is called approx log(n) times
        Merge(arr, low, mid, high);
    }
}
