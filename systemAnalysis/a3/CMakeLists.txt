cmake_minimum_required(VERSION 3.13)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

add_executable(a3 start.cpp assignment.cpp)
add_executable(working main.cpp SimObj.cpp)
