cmake_minimum_required(VERSION 3.13)

project(assignment1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(headers)

add_executable(assignment1 start.cpp)
add_executable(symTable symbolTableTest.cpp)