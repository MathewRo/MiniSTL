cmake_minimum_required(VERSION 2.8)

get_filename_component(RUNTIME_PATH  ../../ ABSOLUTE)
message(STATUS "Runtime path is " ${RUNTIME_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -rdynamic -ggdb -Wall")

include(${RUNTIME_PATH}/gtest.cmake)

# GTest needs threading support
find_package (Threads)

SET(COVERAGE OFF CACHE BOOL "Coverage")

add_executable(sort_ut 
	${RUNTIME_PATH}/algorithm/sort/source/BubbleSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/SelectionSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/InsertionSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/QuickSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/MergeSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/HeapSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/tests/Sort_UnitTest.cpp
        )

target_link_libraries(sort_ut gtest ${CMAKE_THREAD_LIBS_INIT})
if (COVERAGE)
    target_compile_options(sort_ut PRIVATE --coverage)
    target_link_libraries(sort_ut PRIVATE --coverage)
endif()



# For the library
include_directories(
	${RUNTIME_PATH}/algorithm/sort/includes
        ${RUNTIME_PATH}/utils/includes
	)

add_library(mSort SHARED 
	${RUNTIME_PATH}/algorithm/sort/source/BubbleSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/SelectionSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/InsertionSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/QuickSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/MergeSort.cpp 
        ${RUNTIME_PATH}/algorithm/sort/source/HeapSort.cpp 
        ${RUNTIME_PATH}/utils/source/PrintUtil.cpp
        )

set_target_properties(mSort PROPERTIES VERSION 1.0)
set_target_properties(mSort PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY ../libraries/)
set_target_properties(mSort PROPERTIES PUBLIC_HEADER ${RUNTIME_PATH}
        )

link_directories(	
	${RUNTIME_PATH}/algorithm/sort/libraries
        ${RUNTIME_PATH}/utils/libraries
	)

add_executable(sort
	driver.cpp
	)
set(EXECUTABLE_OUTPUT_PATH  ../bin/)
target_link_libraries(sort mSort)


 