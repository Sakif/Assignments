cmake_minimum_required(VERSION 3.13)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-Ofast -Wall -Wextra -Werror")

add_executable(fib fibonacci.cpp)
add_executable(prime primeFactors.cpp)