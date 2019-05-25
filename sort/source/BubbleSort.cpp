#include "BubbleSort.hpp"
#include <algorithm>

/**
 * Bubble Sort Implementation O(n^2)
 * @param arr
 * 
 * https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/tutorial/
 */
void BubbleSort(std::vector <uint64_t> & arr) {
	uint64_t N = arr.size();

	for (uint64_t i = 0; i < N-1; i++ ) {
		bool swapFlag = false;
		for (uint64_t j = 0; j < N-1-i; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j+1]);
				swapFlag = true;
			}
		}
		if (!swapFlag) return;
	}
}
