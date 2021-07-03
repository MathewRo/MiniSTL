cmake_minimum_required(VERSION 2.8)

get_filename_component(RUNTIME_PATH  ../ ABSOLUTE)
message(STATUS "Runtime path is " ${RUNTIME_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++0x -rdynamic -ggdb -Wall -D${MODE}")

# For the library
include_directories(
	${RUNTIME_PATH}/containers/includes/
        ${RUNTIME_PATH}/tests
	)

add_executable(array
	${RUNTIME_PATH}/containers/tests/array.cpp
	)
add_executable(list
 ${RUNTIME_PATH}/containers/tests/list.cpp
 )

set(EXECUTABLE_OUTPUT_PATH  ../bin/)

