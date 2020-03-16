cmake_minimum_required(VERSION 3.13)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-Os -Wall -Wextra -Werror")

#set(CMAKE_C_COMPILER /usr/bin/gcc)
#set(CMAKE_CXX_COMPILER /usr/bin/g++)

include_directories(headers)

project(Assembler)

#add_executable(assembler src/assembler.cpp src/firstPass.cpp src/secondPass.cpp src/symbols.cpp src/isa.cpp xm2.cpp)

add_executable(t test.cpp) 
