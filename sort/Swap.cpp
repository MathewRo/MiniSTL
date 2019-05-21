#include "Swap.hpp"

void Swap(uint64_t &x, uint64_t &y) {
	uint64_t temp = x;
	x = y;
	y = temp;
}
