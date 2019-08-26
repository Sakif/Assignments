cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Werror")

include_directories(headers SymbolTable Assembler)

add_executable(assembler main.cpp SymbolTable/Symbol.cpp SymbolTable/SymbolTable.cpp Assembler/Assembler.cpp Assembler/tokenize.cpp)