/*
 *
 * MIT License
 *
 * Copyright (c) 2021 Rohit Philip Mathew
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the &quot;Software&quot;), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "InsertionSort.hpp"

/**
 * Function Implementing Insertion Sort
 * @param arr
 * TC O(n^2)
 * 
 */
void InsertionSort(std::vector<size_t>& arr) {
    size_t N = arr.size();
    for (size_t i = 0; i < N; i++) {
        // For each loop we assume i as the max initially
        size_t max = arr[i];
        size_t j = i;
        // Iterate if j is atleast 1 and as long as arr[j-1] is bigger than temp
        while (j > 0 && arr[j - 1] > max) {
            // This is essentially pushing the elements by one
            arr[j] = arr[j-1];
            j -= 1;
        }
        // Finally save the temp to the index where the loop condition
        // was false
        arr[j] = max;
    }
}
