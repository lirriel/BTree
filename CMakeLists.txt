cmake_minimum_required(VERSION 3.6)
project(src)


add_definitions(-std=c++11)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(main)
add_subdirectory(tests)