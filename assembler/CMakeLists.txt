cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Werror")

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

include_directories(headers)

project(Assembler)

add_executable(assembler src/assembler.cpp src/firstPass.cpp src/secondPass.cpp src/isa.cpp xm2.cpp)
#add_executable(test test.cpp) 
