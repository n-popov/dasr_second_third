cmake_minimum_required(VERSION 3.20)
project(dasr_second_third)

set(CMAKE_CXX_STANDARD 20)

add_executable(dasr_second_third main.cpp)
add_executable(dispatcher dispatcher.cpp)
add_executable(handler handler.cpp)
