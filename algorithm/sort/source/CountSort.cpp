/*
 *
 * MIT License
 *
 * Copyright (c) 2021 Rohit Philip Mathew
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

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
