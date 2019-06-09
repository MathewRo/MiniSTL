#include "HeapSort.hpp"
#include <algorithm>

void HeapSort(std::vector<size_t> & arr) {
    int N = arr.size(), i = 0;
    while (i < N) {
        make_heap(arr.begin(), arr.end() - i);
        // swap the biggest with its right position
        std::swap(arr.front(), arr[N - i - 1]);
        i++;
    }
}
