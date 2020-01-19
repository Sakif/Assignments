cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Werror")

include_directories(headers symbolTable assembler)

project(Assembler)

add_executable(assembler main.cpp symbolTable/symbol.cpp symbolTable/symbolTable.cpp assembler/assembler.cpp)
