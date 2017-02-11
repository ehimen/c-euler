cmake_minimum_required(VERSION 3.6)
project(c-euler)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES run.c)
add_executable(c-euler ${SOURCE_FILES})
target_link_libraries(c-euler m)