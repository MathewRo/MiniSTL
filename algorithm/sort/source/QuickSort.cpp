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
static size_t Partition(std::vector<size_t> & arr, const size_t & low, const size_t & high) {
    
    int64_t i = low - 1;
    size_t pivot = arr[high];
    // This loop ensures that all the elements to 
    // the right of  pivot are smaller than pivot and 
    // all the elements to the left of pivot are larger
    // than pivot. This implies that pivot gets moves to its
    // original position after the loop gets over. O(n)
    for (size_t j = low; j < high ; j++) {
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
void QuickSort(std::vector <size_t> & arr, const size_t & low, const size_t & high) {
    if (low < high) {
        size_t p = Partition(arr, low, high);
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
void QuickSortIterative(std::vector<size_t>& arr, const size_t& low, const size_t& high) {
    std::stack<std::pair<size_t, size_t > > rangeStack;
    rangeStack.push(std::make_pair(low, high));
    
    while (!rangeStack.empty()) {
        size_t start = rangeStack.top().first;
        size_t end = rangeStack.top().second;
        rangeStack.pop();
        // find the pivot
        size_t p = Partition(arr, start, end);
        if (p - 1 > start) rangeStack.push(std::make_pair(start, p - 1));
        if (end > p + 1) rangeStack.push(std::make_pair(p + 1, end));
    }
}
