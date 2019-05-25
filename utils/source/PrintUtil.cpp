#include "PrintUtil.hpp"
#include <sstream>
#include <iostream>

void PrintArray(const std::vector<uint64_t> & arr) {
#if 0    
    for (std::vector<uint64_t> :: const_iterator c_it = arr.begin(); c_it != arr.end(); c_it++) {
        std::cout << *c_it << " " ;
    }
    std::cout << std::endl;
#endif    
}

const std::string PrintTime(std::chrono::high_resolution_clock::time_point & tStart,
        std::chrono::high_resolution_clock::time_point tStop) {
    
    std::stringstream ss;
    // ns
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(tStop - tStart);
    if (duration.count() > 1000) {
        // us 
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(tStop - tStart);
        if (duration.count() > 1000) {
            // ms 
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(tStop - tStart);
            if (duration.count() > 1000) {
                // s
                auto duration = std::chrono::duration_cast<std::chrono::seconds>(tStop - tStart);
                
                if (duration.count() > 1000) {
                    auto duration = std::chrono::duration_cast<std::chrono::minutes>(tStop - tStart);
                    ss << duration.count() << " min";
                } else {
                    ss << duration.count() << " s";
                }                
            } else {
            ss << duration.count() << " ms";
            }
        } else {
        ss << duration.count() << " us";
        }
    }else {
    ss << duration.count() << " ns";
    }
    
    return ss.str();
}

