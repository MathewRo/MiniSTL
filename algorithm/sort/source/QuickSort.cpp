#include <algorithm>
#include "QuickSort.hpp"
#include <stack>

/**
 *  Helper partition function
 * @param arr
 * @param low
 * @param high
 * @return 
 */
static uint64_t Partition(std::vector<uint64_t> & arr, const uint64_t & low, const uint64_t & high) {
    
    int64_t i = low - 1;
    uint64_t pivot = arr[high];
    // This loop ensures that all the elements to 
    // the right of  pivot are smaller than pivot and 
    // all the elements to the left of pivot are larger
    // than pivot. This implies that pivot gets moves to its
    // original position after the loop gets over. O(n)
    for (uint64_t j = low; j < high ; j++) {
        if ( arr[j] < pivot ) {
            i += 1;
            std::swap(arr[i], arr[j]);
        }
    }
    // i+1 would be the new index of pivot
    std::swap(arr[high], arr[i+1]);
    return  i + 1;
}

/**
 * Recursive quick sort algorithm. 
 * https://www.geeksforgeeks.org/quick-sort/
 * @param arr - array to be sorted in place
 * @param low - lowest index 
 * @param high - highest index
 */
void QuickSort(std::vector <uint64_t> & arr, const uint64_t & low, const uint64_t & high) {
    if (low < high) {
        uint64_t p = Partition(arr, low, high);
        //This is supposed to be log(n) operation
        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high );
    }
}

/**
 * Iterative Quick Sort
 * @param arr
 * @param low
 * @param high
 */
void QuickSortIterative(std::vector<uint64_t>& arr, const uint64_t& low, const uint64_t& high) {
    std::stack<std::pair<uint64_t, uint64_t > > rangeStack;
    rangeStack.push(std::make_pair(low, high));
    
    while (!rangeStack.empty()) {
        uint64_t start = rangeStack.top().first;
        uint64_t end = rangeStack.top().second;
        rangeStack.pop();
        // find the pivot
        uint64_t p = Partition(arr, start, end);
        if (p - 1 > start) rangeStack.push(std::make_pair(start, p - 1));
        if (end > p + 1) rangeStack.push(std::make_pair(p + 1, end));
    }
}
