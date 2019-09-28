#include "CountSort.hpp"
#include <algorithm>
#include <stdint.h>
#include <string>

/**
 * This method takes O(n+k) auxillary space
 * cap with low input
 * @param arr
 */
void CountSort(std::vector <size_t> & arr) {
    auto min = *std::min_element(arr.begin(), arr.end());
    auto max = *std::max_element(arr.begin(), arr.end());
    // TODO throw here
    if (max > 10000) {
        std::string s("array max too big, cant sort!");
        throw s;
    } 
     
    auto count_vec_size = max - min + 1;
    std::vector <size_t> count(count_vec_size), out(arr.size());
    
    for (size_t i = 0; i < arr.size(); i++) {
        count[arr[i]-min]++;
    }
    
    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i-1];
    }
    
    for (size_t i = arr.size() - 1; (int64_t)i >= 0; i-- ) {
        out[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    arr = out;
}