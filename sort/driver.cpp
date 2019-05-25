#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdint>
#include <ctime>
#include <vector>
#include <chrono>
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"


#define ERROR 1
#define SUCCESS 0

#define CURRENT_TIME 0


void Display(const std::vector<uint64_t> & arr) {
    for (std::vector<uint64_t> :: const_iterator c_it = arr.begin(); c_it != arr.end(); c_it++) {
        std::cout << *c_it << " " ;
    }
    std::cout << std::endl;
}

/**
 * Input from command line
 * <BubbleSort> <N>
 */
int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cerr << "ERROR: usage "<< argv[0] << " N" << std::endl;
        return ERROR;
    }
    
    uint64_t N = atol(argv[1]);
    std::vector<uint64_t> array(N);
    
    /* use current time */
    srand(time(NULL));
    
    for (uint64_t i = 0; i < N; i++) {
        array.push_back(rand()%N);
    }
    
#if 0	
    {
	//Display(array);
        auto startTime = std::chrono::high_resolution_clock::now();
	BubbleSort(array);
        auto stopTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
	//Display(array);
	std::cout << "BubbleSort - elapsed time : " << duration.count() << " us" <<std::endl;
    }
#endif
    
    {
	//Display(array);
        auto startTime = std::chrono::high_resolution_clock::now();
	SelectionSort(array);
        auto stopTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
	//Display(array);
	std::cout << "SelectionSort - elapsed time : " << duration.count() << " us" <<std::endl; 
    }
    
    return SUCCESS;
}
