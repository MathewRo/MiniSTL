#ifndef PRINTUTIL_HPP
#define PRINTUTIL_HPP
#include <vector>
#include <cstdint>
#include <chrono>
#include <string>

void PrintArray(const std::vector<uint64_t> & arr);
const std::string PrintTime(std::chrono::high_resolution_clock::time_point & tStart,
        std::chrono::high_resolution_clock::time_point tStop);

#endif /* PRINTUTIL_HPP */

