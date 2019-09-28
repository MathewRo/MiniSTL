#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include <cstdint>
#include <vector>
#include <cstdint>
#include <Common.hpp>

EXPORT_API void QuickSort(std::vector <size_t> & arr, const int64_t & low, const int64_t & high);
EXPORT_API void QuickSortIterative(std::vector <size_t> & arr, const int64_t & low, const int64_t & high);

#endif /* QUICKSORT_HPP */

