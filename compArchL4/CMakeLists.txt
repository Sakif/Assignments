cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(C_STANDARD 18)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

project(lab4)
#add_executable(lab main.cpp)
add_executable(ldstr loadStoreRel.cpp)
