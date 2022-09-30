cmake_minimum_required(VERSION 3.23)
project(Bell)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE Bell_SRC "*.h" "*.cpp")

add_executable(Bell ${Bell_SRC})
