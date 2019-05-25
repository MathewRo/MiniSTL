#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdint>
#include <ctime>
#include <vector>
#include <chrono>
#include <limits.h>
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "PrintUtil.hpp"

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
    
    uint64_t N = atol(argv[1]);
    std::vector<uint64_t> array;
    
    /* use current time */
    srand(time(NULL));
    
    for (uint64_t i = 0; i < N; i++) {
        array.push_back(rand()%INT_MAX);
    }
    
#if 1	
    {
	PrintArray(array);
        auto startTime = std::chrono::high_resolution_clock::now();
	BubbleSort(array);
        auto stopTime = std::chrono::high_resolution_clock::now();
	PrintArray(array);
	std::cout << "BubbleSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
    }

    
    {
	PrintArray(array);
        auto startTime = std::chrono::high_resolution_clock::now();
	SelectionSort(array);
        auto stopTime = std::chrono::high_resolution_clock::now();
	PrintArray(array);
	std::cout << "SelectionSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
    }
#endif    
    {
	PrintArray(array);
        auto startTime = std::chrono::high_resolution_clock::now();
	InsertionSort(array);
        auto stopTime = std::chrono::high_resolution_clock::now();
	PrintArray(array);
	std::cout << "InsertionSort - elapsed time : " << PrintTime(startTime, stopTime) <<std::endl; 
    }

    return SUCCESS;
}
