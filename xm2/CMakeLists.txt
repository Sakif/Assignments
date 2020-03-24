cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_C_COMPILER /usr/bin/clang)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Werror -ferror-limit=5")

project(Assembler)

add_executable(assembler main.cpp assembler.cpp symbols.cpp firstPass.cpp commands.cpp)

