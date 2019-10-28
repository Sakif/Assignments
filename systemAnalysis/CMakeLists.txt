cmake_minimum_required(VERSION 3.13)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(l1t1 fibonacci.cpp)
add_executable(l1t2 primeFactors.cpp)
add_executable(l2t1 lab2task1.cpp)
add_executable(l2t2 lab2task2.cpp)
add_executable(checkedLab checkedLab1/checkedLab1.cpp)
