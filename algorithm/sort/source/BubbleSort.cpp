#include "BubbleSort.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
/**
 * Bubble Sort Implementation O(n^2)
 * @param arr
 * 
 */
void BubbleSort(std::vector <size_t> & arr) {
	int64_t N = arr.size();

	for (int64_t i = 0; i < N-1; i++ ) {
		bool swapFlag = false;
		for (int64_t j = 0; j < N-1-i; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j+1]);
				swapFlag = true;
			}
		}
		if (!swapFlag) return;
	}
}
