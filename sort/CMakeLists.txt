cmake_minimum_required(VERSION 2.8)

get_filename_component(RUNTIME_PATH  ../ ABSOLUTE)
message(STATUS ${RUNTIME_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
	${RUNTIME_PATH}/sort
	)
link_directories(	
	${RUNTIME_PATH}/sort
	)

add_executable( bsort
	BubbleSort.cpp
	Swap.cpp
	driver.cpp
	)
target_link_libraries(bsort)

