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

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstddef>
#include <ctime>
#include <vector>
#include <chrono>
#include <limits.h>
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "QuickSort.hpp"
#include "MergeSort.hpp"
#include "PrintUtil.hpp"
#include "HeapSort.hpp"
#include "CountSort.hpp"

#define ERROR 1
#define SUCCESS 0

#define CURRENT_TIME 0


/**
 * Input from command line
 * <sort> <N>
 */
int main(int argc, char ** argv) {
  if (argc < 2) {
    std::cerr << "ERROR: usage "<< argv[0] << " N" << std::endl;
    return ERROR;
  }

  size_t N = atol(argv[1]);
  std::vector<size_t> array;

  /* use current time */
  srand(time(NULL));

  for (size_t i = 0; i < N; i++) {
    array.push_back(rand()%100);
  }
  std::vector<size_t> arr_cpy(array);
#if 1	
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    BubbleSort(array);
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "BubbleSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

  array = arr_cpy;
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    SelectionSort(array);
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "SelectionSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

  array = arr_cpy;
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    InsertionSort(array);
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "InsertionSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

#endif    
  array = arr_cpy;
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    QuickSort(array, 0, array.size() - 1);
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "QuickSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

  array = arr_cpy;
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    QuickSortIterative(array, 0, array.size() - 1);
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "QuickSort Iterative - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

  array = arr_cpy;
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    MergeSort(array, 0, array.size() - 1);
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "MergeSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

  array = arr_cpy;
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    MergeSortIterative(array, 0, array.size() - 1);
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "MergeSortIterative - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

  array = arr_cpy;
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    HeapSort(array);
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "HeapSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

  array = arr_cpy;
  {
    PrintArray(array);
    auto startTime = std::chrono::high_resolution_clock::now();
    try {
      CountSort(array);
    } catch (std::string s) {
      std::cerr << s << std::endl;
    }
    auto stopTime = std::chrono::high_resolution_clock::now();
    PrintArray(array);
    std::cout << "CountSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
  }

  return SUCCESS;
}
