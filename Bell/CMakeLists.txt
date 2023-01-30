cmake_minimum_required(VERSION 3.23)
project(Bell)

set(CMAKE_CXX_STANDARD 23)

file(GLOB Bell_SRC Bell/*.h Bell/*.cpp)

add_library(Bell ${Bell_SRC})

target_include_directories(Bell PUBLIC Bell)
target_link_directories(Bell PUBLIC Bell)
