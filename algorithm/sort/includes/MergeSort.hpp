#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include <vector>
#include <cstddef>
#include <cstdint>
#include <Common.hpp>

EXPORT_API void MergeSort(std::vector <size_t> & arr, const int64_t &low, const int64_t & high);
EXPORT_API void MergeSortIterative(std::vector <size_t> & arr, const int64_t &low, const int64_t & high);

#endif /* MERGESORT_HPP */

