cmake_minimum_required(VERSION 2.8)

get_filename_component(RUNTIME_PATH  ../ ABSOLUTE)
message(STATUS ${RUNTIME_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -rdynamic -ggdb -Wall")
include_directories(
	${RUNTIME_PATH}/sort/includes
        ${RUNTIME_PATH}/utils/includes
	)
link_directories(	
	${RUNTIME_PATH}/sort/libraries
        ${RUNTIME_PATH}/utils/libraries
	)

add_executable( sort
	source/BubbleSort.cpp
        source/SelectionSort.cpp
        source/InsertionSort.cpp
        source/QuickSort.cpp

        ../utils/source/PrintUtil.cpp

	driver.cpp
	)
target_link_libraries(sort)

